// --------------------<optimizations>--------------------
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
// -------------------</optimizations>--------------------
#include <bits/stdc++.h>
#define ll long long
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> //lower_bound , upper_bound
// using namespace __gnu_pbds;//kth smallest : *pd.find_by_order(k-1) , no. of elem < X : pd.order_of_key(X) , delete X : pd.erase(X).
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define f(i, a, b) for (ll i = a; i < b; i++)
#define fb(i, a, b) for (ll i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define nl '\n'
#define pl pair<ll, ll>
#define all(v) v.begin(), v.end()
#define lb lower_bound
#define ub upper_bound
#define nude(a)           \
    for (auto i : a)      \
        cout << i << " "; \
    cout << nl;
#define tc     \
    ll tc;     \
    cin >> tc; \
    while (tc--)
const ll mod = (1e9 + 7);
const ll sz = 2e5 + 9;
#define maxheap priority_queue<ll>
#define minheap priority_queue<ll, vector<ll>, greater<ll>>
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
        {
            res = (res * x) % p;
        }
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

vector<vector<ll>> dp(1e5 + 1, vector<ll>(2, -1));

ll dfs(vector<vector<ll>> &adj, ll cur, ll par, ll col)
{
   
    if (dp[cur][col] == -1)
    {
        dp[cur][col] = 1;
        for (ll x : adj[cur])
        {
            if (x != par)
            {

                if (!col)
                {
                    dp[cur][col] *= (dfs(adj, x, cur, col) + dfs(adj, x, cur, col ^ 1)) % mod;
                    dp[cur][col] %= mod;
                }
                else
                {
                    dp[cur][col] *= dfs(adj, x, cur, col ^ 1) % mod;
                    dp[cur][col] %= mod;
                }
            }
        }
    }

    return dp[cur][col];
}

void bring_me_thanos()
{
    ll n;
    cin >> n;
    vector<vector<ll>> adj(n + 1);
    ll x, y;
    f(i, 0, n - 1)
    {
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(adj, 1, 0, 0);
    dfs(adj, 1, 0, 1);

    cout << (dp[1][0] + dp[1][1]) % mod << nl;
}

void solve()
{
    //init();
    //tc
    bring_me_thanos();
}

int main()
{
#ifdef JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    clock_t beg = clock();
    solve();
    clock_t end = clock();
    fprintf(stderr, "%.3f sec, Copyright %c 2019 PyThor. \n", double(end - beg) / CLOCKS_PER_SEC, 184);
    return 0;
}