#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define ar array
#define db double
#define pow pw
const db pi = 3.14159265358979323846;
int pw(int a,int b){
    int ans=1;
    while(b){
    if (b%2) ans*=a;
    a*=a;
    b/=2;
    }
    return(ans);
}
const int mxn=1e5+7,du=1e9+7;
int n,k;
int dp[mxn];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    dp[0]=1;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        vector<int> sum(k+1);
        for (int j=k;j>=0;j--)
       // for (int take=1;take<=x;take++)
        {
            int l=j+1;
            int r=j+min(x,k-j);
            if (l<=r)
            {
                sum[l]+=dp[j]; sum[l]%=du;
                if (r+1<=k) 
                {
                    sum[r+1]-=dp[j];
                    sum[r+1]=(sum[r+1]+du)%du;
                }
            }
        }
        int pref=0;
        for (int j=0;j<=k;j++)
        {
            pref=(pref+sum[j])%du;
            dp[j]=(dp[j]+pref)%du;
        }
    }
    cout<<dp[k];
    return 0;
}