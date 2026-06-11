#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define bit(n) (1<<(n))
#define ii(x) int x; cin >> (x)
#define ii2(x, y) int x, y; cin >> (x) >> (y)
#define ii3(x, y, z) int x, y, z; cin >> (x) >> (y) >> (z)
#define yn(x, ok, ng) cout << ((x)?(ok):(ng)) << endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
ll const INF = 1e14;


int main()
{
cin.tie(0);
ios::sync_with_stdio(false);

int a,b,Q;
cin >> a >> b >> Q;
vl s(a), t(b), x(Q);
rep(i,a) cin >> s[i];
rep(i,b) cin >> t[i];
rep(i,Q) cin >> x[i];

s.emplace(s.begin(),-INF);
s.emplace(s.begin(),-INF*2);
s.emplace_back(INF);
s.emplace_back(INF*2);
  
t.emplace(t.begin(),-INF);
t.emplace(t.begin(),-INF*2);
t.emplace_back(INF);
t.emplace_back(INF*2);

rep(i,Q) {
    ll res = INF*2;
    ll u = upper_bound(all(s), x[i]) - s.begin();
    ll v = upper_bound(all(t), x[i]) - t.begin();
    for(int j = -1; j <= 1; ++j) {
        for(int k = -1; k <= 1; ++k) {
            chmin(res, abs(s[u+j] - x[i]) + abs(s[u+j] - t[v+k]));
            chmin(res, abs(t[v+k] - x[i]) + abs(s[u+j] - t[v+k]));
        }
    }
    cout << res << endl;
}
return 0;
}