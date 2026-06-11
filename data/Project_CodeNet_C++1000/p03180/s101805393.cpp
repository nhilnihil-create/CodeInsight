#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

#define LEN(x) (int)x.size()
#define ALL(x) x.begin(), x.end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
using vpii = vector<pii>;

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

const ll INF = 1e18;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

inline int fcmp(double x, double y)
{ return (x < y + EPS ? (x < y - EPS ? -1 : 0) : 1);}

const int N = 17, MSK = 1 << N;
ll dp[MSK], c[MSK];
int a[N][N], n;
bool vis[MSK];

ll solve(int msk)
{
    if(msk == 0)
        return 0;

    ll& ans = dp[msk];

    if(!vis[msk])
    {
        ans = -INF;

        for(int sub = msk; sub > 0; sub = (sub - 1) & msk)
            ans = max(ans, c[sub] + solve(msk ^ sub));
        
        vis[msk] = true;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    for(int msk = 0; msk < (1 << n); msk++)
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if((msk & (1 << i)) && (msk & (1 << j))) c[msk] += a[i][j];

    cout << solve((1 << n) - 1) << endl;

    return 0;
}