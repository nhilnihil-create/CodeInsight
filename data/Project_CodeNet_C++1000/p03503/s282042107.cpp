#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(long long i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define rrep(i,n) for(long long i=int(n);i>0;i--)
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+5  
using ll = long long;
using P = pair<int, int>;
using lP = pair<ll, ll>;
using fP = pair<double, double>;
using PPI = pair<P, int>;
//ll const mod=998244353;
ll const mod = 1e9 + 7;
const ll MAX = 1000005;
using vi = vector<int>;
using vl = vector<ll>;
using vc = vector<char>;
using vd = vector<double>;
using vs = vector<string>;
using vp = vector<P>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvd = vector<vector<double>>;
using vvc = vector<vector<char>>;
using vvp = vector<vector<P>>;
using vvb = vector<vector<bool>>;
template <typename T>
bool chmax(T& a, const T b) { if (a < b) { a = b; return true; } return false; }
template <typename T>
bool chmin(T& a, const T b) { if (a > b) { a = b; return true; } return false; }
const ll LINF = 1e18 + 1;
int main() {
    int n;
    cin >> n;
    vvi f(n, vi(20));
    rep(i, n) {
        rep(j, 10) {
            cin >> f[i][j];
        }
    }
    vvi p(n, vi(15));
    rep(i, n)rep(j, 11)cin >> p[i][j];
    ll ans = -LINF;
    arep(i, 1, 1 << 10) {
        ll res = 0;
        vi cnt(n);
        rep(j, 10) {
            if (i >> j & 1) {
                rep(k, n) {
                    if (f[k][j] == 1)cnt[k]++;
                }
            }
        }
        rep(i, n)res += p[i][cnt[i]];
        chmax(ans, res);
    }
    cout << ans << endl;
    return 0;
}