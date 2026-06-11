#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>; 
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1001001001001001001;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main(){
    int n, k; cin >> n >> k;
    vector<ll> X(n), Y(n);
    rep(i, n) cin >> X[i] >> Y[i];

    ll res = LLONG_MAX;
	rep(a, n){
      rep(b, n){
        rep(c, n){
          rep(d, n){
          	ll lx = X[a], rx = X[b], ly = Y[c] , ry = Y[d];
            if(lx >= rx || ly >= ry)continue;
            //構成された長方形が含む点の数を数える
            int cnt = 0;
            rep(i, n){
              ll x = X[i], y = Y[i];
              if(x >= lx && x <= rx && y >= ly && y <= ry)cnt++;
            }
            if(cnt==k){
              ll area = (rx - lx) * (ry - ly);
              chmin(res, area);
            }
          }
        }
      }
    }
    cout << res << ln;
}
