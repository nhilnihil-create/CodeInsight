/* Simplicity and Goodness */

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;
using namespace std;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//             tree_order_statistics_node_update> indexed_set;

void my_dbg() { cout << endl; }
template<typename Arg, typename... Args> void my_dbg(Arg A, Args... B)
{ cout << ' ' << A; my_dbg(B...); }
#define dbg(...)  cout << "(" << #__VA_ARGS__ << "):", my_dbg(__VA_ARGS__)

#define scn(n) scanf("%d", &n)
#define lscn(n) scanf("%lld", &n)
#define pri(n) printf("%d ", (int)(n))
#define prin(n) printf("%d\n", (int)(n))
#define lpri(n) printf("%lld ", n)
#define lprin(n) printf("%lld\n", n)
#define rep(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

const int inf = INT_MAX;
const int ninf = INT_MIN;
const int mod = 1e9+7;
const int N = 402;

ll dp[N][N], a[N];

ll rec(int i, int j)
{
    if(i == j)
        return 0;

    ll& ans = dp[i][j];

    if(ans != -1)
        return ans;

    ll sum = 0;

    rep(k, i, j+1)
    sum += a[k];

    ans = (ll) 1e18;

    rep(k, i, j+1) {
        ans = min(ans, rec(i, k) + rec(k+1, j) + sum);
    }

    return ans;
}

void solve()
{
    int n;
    scn(n);

    memset(dp, -1, sizeof(dp));

    rep(i, 0, n)
    lscn(a[i]);

    lprin(rec(0, n-1));
}

int main()
{
    int t = 1;
    // scn(t);

    while(t --) {
        solve();
    }
    return 0;
}