#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define bit(n) (1<<(n))
#define fi first
#define se second
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
int const INF = 1001001001;

int n,a,b,c;
int l[10];
int ans;

void dfs (vector<int> table, int v) {
    table.push_back(v);
    if(SZ(table) == n) {
        vi vec(3), cnt(3);
        rep(i,n) {
            rep(j, 3) {
                if(table[i] == j) vec[j] += l[i], cnt[j]++;
            }
        }
        if (cnt[0] != 0 && cnt[1] != 0 && cnt[2] != 0) {
            sort(vec.rbegin(), vec.rend());
            int cur = abs(a - vec[0]) + abs(b - vec[1]) + abs(c - vec[2]);
            rep(j,3) cur += 10 * (cnt[j] - 1);
            chmin(ans, cur);
        }
    }
    else {
        rep(nv, 4) {
            dfs(table, nv);
        }
    }
}

int main()
{
cin.tie(0);
ios::sync_with_stdio(false);

cin >> n >> a >> b >> c;
rep(i,n) cin >> l[i];

ans = INF;
rep(sv , 4) dfs({}, sv);
cout << ans << endl;
return 0;
}