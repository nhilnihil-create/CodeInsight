#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(ll i = 0; i < n; i++)
#define P pair<ll, ll>

typedef vector<int> vec;
typedef vector<vec> mat;

bool f(P x, P y){
    if (x.second != y.second) return x.second > y.second;
    else return x.first < y.first;
}

int main(){
    ll n, m;
    cin >> n >> m;
    ll a[n];
    rep(i, n) cin >> a[i];
    P b[m];
    rep(i, m) cin >> b[i].first >> b[i].second;
    sort(a, a + n);
    sort(b, b + m, f);
    ll ans = 0;
    ll idx = 0;
    rep(i, n){
        if(idx < m){
            if(a[i] < b[idx].second) {
                ans += b[idx].second;
                b[idx].first--;
            }else{
                ans += a[i];
                idx = m;
            }
        }else{
            ans += a[i];
        }
        if(b[idx].first == 0) idx++;
    }
    // rep(i, m){
    //     cout << b[i].first << " " << b[i].second << endl;
    // }
    cout << ans << endl;
}