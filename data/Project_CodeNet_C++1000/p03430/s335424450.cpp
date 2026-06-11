


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long

#define all(X) (X).begin(), (X).end()
#define reset(X) memset(X, 0, sizeof(X))
#define mp(a, b) make_pair(a, b)
#define pb push_back
// #define endl '\n'
#define fi first
#define se second

using namespace __gnu_pbds;
using namespace std;
const int mod = 1e9 + 7;
// const int mod=998244353;
//const int mod=1e9+9;
//const int INF=4e18+10;
const int INF = 4e18 + 10;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define read(n) \
int n;      \
cin >> n;
#define readv(x, n)   \
vector<int> x(n); \
for (auto &i : x) \
    cin >> i;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;

template <typename T1, typename T2>
void set_min(T1 &a, T2 b)
{
    a = min(a, (T1)b);
}

int multiply(int a, int b, int in_mod) { return (a * b) % in_mod; }
int mult_identity(int a) { return 1; }


auto power(auto a, int b, int in_mod)
{
    auto prod = mult_identity(a);
    auto mult = a % in_mod;
    while (b != 0)
    {
        if (b % 2)
        {
            prod = multiply(prod, mult, in_mod);
        }
        mult = multiply(mult, mult, in_mod);
        b /= 2;
    }
    return prod;
}
int mod_inv(int q, int in_mod)
{

    return power(q, in_mod - 2, in_mod);
}

int n;
vector<vector<int>> g, gt;
vector<bool>used;
vector<int> order,comp;
vector<bool> assignment;

void dfs1(int v)
{
    used[v] = true;
    for(int u:g[v])
        if(!used[u])
            dfs1(u);
    order.pb(v);
}

void dfs2(int v, int cl)
{
    comp[v] = cl;
    for(auto u:gt[v])
        if(comp[u] ==-1)
            dfs2(u, cl);
}

bool solve_2SAT()
{
    used.assign(n, false);
    for(int i= 0;i<n;i++)
        if(!used[i])
            dfs1(i);

    comp.assign(n,-1);
    for(int i= 0,j=0;i<n;++i)
    {
        int v= order[n-i-1];
        if(comp[v] == -1)
            dfs2(v, j++);
    }
    assignment.assign(n/2, false);
    for(int i= 0;i<n;i+=2)
    {
        if(comp[i] == comp[i+1])

            return false;
        assignment[i/2] = comp[i]>comp[i+1];
    }
    return true;
}


// void  solve()
// {
//     int n;
//     cin>>n;
//     int a, b;
//     cin>>a>>b;
//     readv(p,n);
//     map<int, bool> cnt;
//     for(auto i:p)
//         cnt[i] = true;

//     map<int, int> marking;

//     int ind = 0;
//     for(auto i:p)
//         if(!marking[i])
//             marking[i] = ind++;


//     ::n = 2*ind+2;
//     g.resize(::n);
//     gt.resize(::n);
//     for(auto i:p)
//     {
//         int it = marking[i];
//         int other = marking[a-i];
//         int otherother = marking[b-i];
//         if(cnt[a-i])
//         {
//             g[2*it].pb(2*other);
//             g[2*it+1].pb(2*it);
//             g[2*other].pb(2*it);
//             g[2*other+1].pb(2*other);

//             gt[2*other].pb(2*it);
//             gt[2*it].pb(2*it+1);

//             gt[2*it].pb(2*other);
//             gt[2*other].pb(2*other+1);
//         }
//         else
//         {

//             if(cnt[b-i])
//             {

//                 g[2*it+1].pb(2*otherother+1);
//                 g[2*it].pb(2*it+1);
//                 g[2*otherother+1].pb(2*it+1);
//                 g[2*otherother].pb(2*otherother+1);

//                 gt[2*otherother+1].pb(2*it+1);
//                 gt[2*it+1].pb(2*it);
//                 gt[2*it+1].pb(2*otherother+1);
//                 gt[2*otherother + 1].pb(2*otherother);

//             }
//             else
//             {
//                 cout<<"NO"<<endl;
//                 return;
//             }
//         }
//         if(cnt[a-i] && cnt[b-i])
//         {
//                 g[2*it].pb(2*otherother);
//                 g[2*it].pb(2*other);
//                 g[2*it+1].pb(2*otherother+1);
//                 g[2*it+1].pb(2*other+1);

//                 g[2*otherother].pb(2*it);
//                 g[2*otherother].pb(2*other);
//                 g[2*otherother+1].pb(2*it+1);
//                 g[2*otherother+1].pb(2*other+1);

//                 g[2*other].pb(2*it);
//                 g[2*other].pb(2*otherother);
//                 g[2*other+1].pb(2*otherother+1);
//                 g[2*other + 1].pb(2*it + 1);

//                 gt[2*it].pb(2*otherother);
//                 gt[2*it].pb(2*other);
//                 gt[2*it+1].pb(2*otherother+1);
//                 gt[2*it+1].pb(2*other+1);

//                 gt[2*otherother].pb(2*it);
//                 gt[2*otherother].pb(2*other);
//                 gt[2*otherother+1].pb(2*it+1);
//                 gt[2*otherother+1].pb(2*other+1);

//                 gt[2*other].pb(2*it);
//                 gt[2*other].pb(2*otherother);
//                 gt[2*other+1].pb(2*otherother+1);
//                 gt[2*other + 1].pb(2*it + 1);
//         }
//     }

//     bool flag = solve_2SAT();

//     if(flag)
//     {
//         cout<<"YES"<<endl;
//         for(auto i:p)
//             cout<<1-assignment[marking[i]]<<" ";
//     }
//     else
//     {
//         cerr<<"method1"<<endl;
//         cout<<"NO"<<endl;
//     }

// }
void solve()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    int n= s.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k+1)));


    for(int len = 1;len<=n;len++)
    {
        for(int l = 0;l+len-1<n;l++)
        {
            int r= l+len-1;
            for(int _k=0;_k<=k;_k++)
            {
                if(len == 1)
                    dp[l][r][_k] =1;
                else
                {
                    if(s[l] == s[r])
                        dp[l][r][_k] =2 +dp[l+1][r-1][_k];
                    else
                    {
                        dp[l][r][_k] = max(dp[l+1][r][_k], dp[l][r-1][_k]);
                        if(_k)
                            dp[l][r][_k] = max(dp[l][r][_k], 2+dp[l+1][r-1][_k-1]); 
                    }
                }
            }
        }
    }
    cout<<dp[0][n-1][k]<<endl;
}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cerr.tie(NULL);
#ifndef ONLINE_JUDGE
    if (fopen("INPUT.txt", "r"))
    {
        freopen("INPUT.txt", "r", stdin);
        freopen("OUTPUT.txt", "w", stdout);
    }
#endif
    auto clk = clock();
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // -------------------------------------Code starts here---------------------------------------------------------------------

    int t = 1;
    // cin >> t;

    for (int test = 1; test <= t; test++)
    {
        // cout<<"Case #"<<test<<":\n";
        //cout<<"Trip #"<<test<<": ";
        // cout<<endl;
        solve();
        // solveB();

        // cout<<endl;
    }

    // -------------------------------------Code ends here------------------------------------------------------------------

    clk = clock() - clk;
    // cerr << fixed << setprecision(6) << "Time: " << ((long double)clk) / CLOCKS_PER_SEC << "\n";
    return 0;
}
