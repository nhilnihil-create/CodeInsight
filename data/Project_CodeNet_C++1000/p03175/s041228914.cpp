
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ub              upper_bound
#define lb              lower_bound
#define isrt            insert
#define clr             clear
#define rsz             resize
#define ff              first
#define ss              second
#define lli             long long int
#define pb              push_back
#define pf              push_front
#define mkp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<lli,lli>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define INF             1e9
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define all(v)          v.begin(),v.end()
#define endl            "\n"


typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

lli maxm(lli a, lli b)
{
    return (a >= b ? a : b);
}


lli minm(lli a, lli b)
{
    return (a <= b ? a : b);
}

lli power(lli x, lli y, lli p)
{
    lli res = 1;

    x = x % p;
    if (x == 0)
        return 0;

    while (y > 0)
    {

        if (y & 1)
            res = (res * x) % p;


        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

lli nCrmodp(lli n, lli r, lli p)
{
    if (r == 0)
        return 1;
    if (r == 1)
        return n;


    lli pro = 1, k = n;
    while (k > r)
    {
        pro *= k;
        pro %= p;
        --k;
    }

    k = 2;
    while (k <= (n - r))
    {
        pro *= power(k, (p - 2), p);
        pro %= p;
        ++k;
    }

    return pro;
}


string num_str(lli n, lli k)
{
    string str = "";
    lli x = n;
    while (x != 0)
    {
        string s = to_string(x % k);
        str = s + str;
        x /= k;
    }

    return str;
}


lli first_big(lli n, lli k, lli arr[])
{
    lli l = 0;
    lli r = n - 1;

    lli leftGreater = n;

    while (l <= r) {
        lli m = l + (r - l) / 2;

        if (arr[m] > k) {
            leftGreater = m;
            r = m - 1;
        }

        else
            l = m + 1;
    }

    return leftGreater;
}

void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

#define MAXN 100005
vector<int>adj[MAXN];
lli arr[MAXN][2];
vector<bool>vis;

lli dfs(int s, int par, bool st)
{
    vis[s] = true;
    int indx = 0;
    if (st == 1)
        indx = 1;

    if (arr[s][indx] == -1)
    {
        if (adj[s].size() == 1 && s != 1)
            arr[s][indx] = 1;

        else
        {
            lli pro = 1;

            if (indx == 1)
                for (auto it : adj[s])
                {
                    if (it != par)
                        pro *= dfs(it, s, false);
                    pro %= mod;
                }

            else
                for (auto it : adj[s])
                {
                    if (it != par)
                        pro *= (dfs(it, s, true) + dfs(it, s, false));
                    pro %= mod;
                }

            arr[s][indx] = pro;

        }
    }
    return arr[s][indx];
}


int main()
{
    c_p_c();

    int n, u, v;
    cin >> n;

    vis.rsz(n + 1, false);
    memset(arr, -1, sizeof(arr));


    for (int i = 1; i < n; ++i)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    if (n == 1)
        cout << "2\n";
    else
        cout << (dfs(1, 0, true) + dfs(1, 0, false)) % mod << endl;

    return 0;
}