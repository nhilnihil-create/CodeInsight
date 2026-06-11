#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> II;
typedef pair<long long, int> LLI;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<II> VII;

#define For(i,a,b) for(int i = a;i <= b; i++)
#define Rep(i,a,b) for(int i = a;i >= b; i--)
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, f) for(auto i : f)
#define fi first
#define se second
#define pb push_back
#define sz(s) int(s.size())
#define reset(f, x) memset(f, x, sizeof(f))
#define all(x) x.begin(), x.end()
#define two(x) (1LL << x)
#define getbit(x, i) ((x >> (i-1)) & 1LL)
#define onbit(x, i) (x | (1LL << (i-1)))
#define offbit(x, i) (x & ~(1 << (i-1)))

const int N = 1e5+10;

int n;
LL x[2][N], v[N], s[2][N], f[2][N], res, C;

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("in.txt","r",stdin);
    //freopen("","w",stdout);
    cin >> n >> C;
    For(i, 1, n) cin >> x[0][i] >> v[i];
    For(i, 1, n) x[1][i] = C - x[0][i];
    For(i, 1, n) {
        s[0][i] = s[0][i-1] + v[i];
        f[0][i] = max(f[0][i-1], s[0][i] - x[0][i]);
        res = max(res, f[0][i]);
    }
    Rep(i, n, 1) {
        s[1][i] = s[1][i+1] + v[i];
        f[1][i] = max(f[1][i+1], s[1][i] - x[1][i]);
        res = max(res, f[1][i]);
        res = max(res, s[1][i] - 2LL*x[1][i] + f[0][i-1]);
        res = max(res, s[0][i] - 2LL*x[0][i] + f[1][i+1]);
    }
    cout << res << "\n";
    //For(i, 1, n) cout << f[1][i] << ' ';
}


