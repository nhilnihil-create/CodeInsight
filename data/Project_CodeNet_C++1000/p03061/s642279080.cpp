
#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n-1); i >= 0; i--)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
const int IINF = 1000000000;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll gcd(ll x, ll y){
    if (y==0) return x;
    else return gcd(y, x%y);
}

int main(){

    int N; cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    
    vector<ll> left_gcd_sum(N);
    vector<ll> right_gcd_sum(N);

    left_gcd_sum[0] = A[0];
    right_gcd_sum[N-1] = A[N-1];
    for(int i = 1; i < N; i++){
        left_gcd_sum[i] = gcd(left_gcd_sum[i-1],A[i]);
        right_gcd_sum[N-1-i] = gcd(right_gcd_sum[N-i], A[N-1-i]);
    }
    

    ll ans = 1;
    rep(i,N){
        ll current_gcd;
        if (i == 0) current_gcd = right_gcd_sum[1];
        else if(i == N-1) current_gcd = left_gcd_sum[N-2];
        else current_gcd = gcd(left_gcd_sum[i-1], right_gcd_sum[i+1]);
        ans = max(ans, current_gcd);
    }

    cout << ans << endl;
    
}