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
const int mxn=1e3+7,du=1e9+7;
int m,n;
char a[mxn][mxn];
int dp[mxn][mxn];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>m>>n;  
    for (int i=1;i<=m;i++) for (int j=1;j<=n;j++) cin>>a[i][j];
    dp[1][1]=1;
    for (int i=1;i<=m;i++)
    for (int j=1;j<=n;j++) 
    {
    if (i==1&&j==1) continue;
    if (a[i][j]=='.') dp[i][j]=(dp[i-1][j]+dp[i][j-1])%du;
    else dp[i][j]=0;
    }
    cout<<dp[m][n];
    return 0;
}