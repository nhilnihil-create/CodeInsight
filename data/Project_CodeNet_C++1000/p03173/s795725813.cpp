#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/trie_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
using ll = long long;
const int mxn=405;
const ll INF=2e18+2;
int n;
int a[mxn];
ll dp[mxn][mxn];
ll sum[mxn];
ll getsum(int l,int r)
{
    return(sum[r]-sum[l-1]);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for (int l=n;l>=1;l--)
    for (int r=l;r<=n;r++)
    {
        dp[l][r]=INF;
        if (l==r) dp[l][r]=0;
        else
        for (int i=l;i<=r;i++)
        {
            dp[l][r]=min(dp[l][r],dp[l][i]+dp[i+1][r]+getsum(l,r));
        }
    }
    cout<<dp[1][n];
}
