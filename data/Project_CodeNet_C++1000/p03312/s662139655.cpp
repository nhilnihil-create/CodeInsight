#include<bits/stdc++.h>
using namespace std;
#define ll long long
template<class T> void chmax(T& x, T y){if(x < y) x = y;}
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
int N;
ll A[200010];
vector<ll> sum;

ll solve(int c){
    if(c == N - 2) return 1e17;

    ll mid = sum[c] / 2;
    ll mx1 = 0;
    ll mn1 = (ll)1e17;
    int b = upper_bound(sum.begin(), sum.end(), mid) - sum.begin();
    
    ll gap = 1e17;
    if(b < c){
        gap = sum[b] * (ll)2 - sum[c];
        mx1 = sum[b];
        mn1 = sum[c] - sum[b];
    }
    if(0 < b){
        ll gap2 = sum[c] - sum[b - 1] * (ll)2;
        if(gap > gap2){
            gap = gap2;
            mx1 = sum[c] - sum[b - 1];
            mn1 = sum[b - 1];
        }
    }

    gap = 1e17;
    mid = (sum[N - 1] - sum[c]) / 2 + sum[c];
    ll mx2 = 0;
    ll mn2 = (ll)1e17;
    int d = upper_bound(sum.begin(), sum.end(), mid) - sum.begin();

    if(d < N - 1){
        gap = sum[d] - sum[c] - (sum[N - 1] - sum[d]);
        mx2 = sum[d] - sum[c];
        mn2 = sum[N - 1] - sum[d];
    }
    if(c + 1 < d){
        ll gap2 = (sum[N - 1] - sum[d - 1]) - (sum[d - 1] - sum[c]);
        if(gap > gap2){
            mx2 = sum[N - 1] - sum[d - 1];
            mn2 = sum[d - 1] - sum[c];
        }
    }

    ll mx = max(mx1, mx2);
    ll mn = min(mn1, mn2);

    return min(mx - mn, solve(c + 1));
}


int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        sum.push_back(A[i]);
    }
    for(int i = 1; i < N; i++){
        sum[i] += sum[i - 1];
    }
    cout << solve(1);
}