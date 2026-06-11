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
string a,b;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b;
    int m=a.length(),n=b.length();
    a=" "+a;
    b=" "+b;
    vector<vector<int> > dp(m+1,vector<int>(n+1));
    for (int i=1;i<=m;i++)
    for (int j=1;j<=n;j++) 
    if (a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    string ans="";
    while(m>0&&n>0)
    {
        if (a[m]==b[n]&&dp[m][n]==dp[m-1][n-1]+1) 
        {
            ans+=a[m];
            m--;
            n--;
        }
        else if (dp[m][n]==dp[m-1][n]) m--;
        else n--;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
    return 0;
}