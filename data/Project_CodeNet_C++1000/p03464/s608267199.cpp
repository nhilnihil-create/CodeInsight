#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = LLONG_MAX;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int K;
    cin >> K;
    ll A[K];
    rep(i, K) cin >> A[i];
    ll L = 0, R = INF;
    while(L < R){
        ll N = (L+R+1)/2, res= N;
        rep(i, K){
            res -= res%A[i];
        }
        if(res <= 2) L = N;
        else R = N-1;
    }
    ll l = 0, r = INF;
    while(l < r){
        ll n = (l+r)/2, res = n;
        rep(i, K){
            res -= res%A[i];
        }
        if(res < 2) l = n+1;
        else r = n;
    }
    ll res = l;
    rep(i, K){
        res -= res%A[i];
    }
    if(res != 2) cout << -1 << endl;
    else cout << l << ' ' << L << endl;
}