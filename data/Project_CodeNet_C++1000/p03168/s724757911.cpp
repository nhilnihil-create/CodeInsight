#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define ar array
#define db long double
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
const int mxn=3001;
int n;
db a[mxn];
db dp[mxn];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    dp[0]=1;
    for (int i=1;i<=n;i++)
    {
        for (int j=i;j>=0;j--)
        dp[j]=(j>0?dp[j-1]*a[i]:0)+dp[j]*(1-a[i]);
    }
    db ans=0;
    for (int i=n;i>=0;i--)
    {
        int j=n-i;
        if (j>i) break;
        ans+=dp[i];
    }
    cout<<fixed<<setprecision(9)<<ans;
    return 0;
}