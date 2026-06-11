#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int n; cin >> n;
    vector<ll> X(n), Y(n), h(n);
    int si = -1;
    rep(i, n){
        cin >> X[i] >> Y[i] >> h[i];
        if(h[i] > 0) si = i;
    }

    ll res[3];
    rep(i, 101){
        rep(j, 101){
            ll H = h[si] + abs(X[si]-i) + abs(Y[si]-j);
            bool ok = true;
            rep(k, n){
                if(h[k]>0 && H-h[k] != abs(X[k]-i) + abs(Y[k]-j)) ok = false;
                if(h[k]==0 && H > abs(X[k]-i) + abs(Y[k]-j)) ok = false;
            }
            if(ok) res[0] = i, res[1] = j, res[2] = H;
        }
    }
    cout << res[0] << " " << res[1] << " " << res[2] << ln;
}
