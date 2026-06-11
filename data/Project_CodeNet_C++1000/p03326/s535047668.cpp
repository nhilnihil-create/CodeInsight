#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<int> dx = {-1, 1};

int main(){
    ll n, m;
    ll ans = 0;
    cin >> n >> m;
    vector<ll> x(n), y(n), z(n);
    rep(i, n) {
        cin >> x[i] >> y[i] >> z[i];
    }
    rep(a, 2) {
        rep(b, 2) {
            rep(c, 2) {
                vector<ll> s(n);
                rep(i, n) {
                    s[i] = dx[a]*x[i] + dx[b]*y[i] + dx[c]*z[i];
                }
                sort(s.begin(), s.end());
                ll res = 0;
                rep(i, m) {
                    res += s[n-i-1];
                }
                chmax(ans, res);
            }
        }
    }
    cout << ans << endl;
}