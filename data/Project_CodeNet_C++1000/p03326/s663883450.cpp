#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<bool> vb;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
long long const INF = 1LL << 60;


int main()
{
    int n,m;
    cin >> n >> m;
    vector<ll> x(n),y(n),z(n);
    rep(i,n) cin >> x[i] >> y[i] >> z[i];


    ll res = -INF;
    rep(p,2) {
        rep(q,2) {
            rep(r,2) {
                vector<ll> v(n);
                rep(i,n) v[i] = (p?1:-1)*x[i] + (q?1:-1)*y[i] + (r?1:-1)*z[i];
                sort(v.rbegin(), v.rend());
                ll sum = 0;
                rep(i,m) sum += v[i];
                chmax(res,sum);
            }
        }
    }
    cout << res << endl;
    return 0;
}