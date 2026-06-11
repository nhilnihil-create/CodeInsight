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

lli dp[110][100010];
vector<lli> arr;
vector<lli> pref_sum;
vector<lli> pr;

int main()
{
    c_p_c();

    lli n, k, s = 0, l, r;

    memset(dp, -1, sizeof(dp));

    cin >> n >> k;
    arr.rsz(n + 1);
    pref_sum.rsz(n + 1);


    for (int i = 0; i <= n; ++i)
        dp[i][0] = 1;
    for (int i = 1; i <= k; ++i)
        dp[0][i] = 0;


    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        s += arr[i];
        pref_sum[i] = s;
    }

    for (int i = 1; i <= n; ++i)
    {
        pr.clr();
        pr.rsz(k + 1);
        s = 0;

        for (int j = 0; j <= k; ++j)
        {
            s += dp[i - 1][j];
            s %= mod;
            pr[j] = s;
        }

        for (int j = 0; j <= k; ++j)
        {
            if (j <= arr[i])
                dp[i][j] = pr[j];

            else
            {
                if (j > pref_sum[i])
                    dp[i][j] = 0;
                else
                {
                    l = (j - arr[i]);
                    r = j;

                    dp[i][j] = (pr[r] - pr[l - 1] + mod) % mod;
                }
            }
        }

    }

    cout << dp[n][k] << endl;


    return 0;
}
