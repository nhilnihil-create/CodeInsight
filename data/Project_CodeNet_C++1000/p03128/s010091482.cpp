#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <iostream>
#define ll long long
using namespace std;
int dp[10000+7];
int t[10]= {0,2,5,5,4,5,6,3,7,6},a[10],b[100];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,i,j,k;
    cin>>n>>m;
    for(i=0; i<m; i++)
        cin>>a[i];
    sort(a,a+m,cmp);
dp[0]=1;
//memset(dp,-1,sizeof(dp));
    for(i=0;i<m;i++)
    {
        for(j=t[a[i]];j<=n;j++)
        {
            if(j&&j>=t[a[i]])dp[j]=max(dp[j],dp[j-t[a[i]]]+1);
        }
    }
   // for(i=0;i<=n;i++)cout<<dp[i]<<endl;
    while(n>0)
    {//cout<<n<<endl;
        for(i=0;i<m;i++)
        {//cout<<a[i]<<" ";
           // cout<<n<<" "<<dp[n]<<"  "<<dp[n-t[a[i]]]<<endl;
            if(n>=t[a[i]]&&dp[n]-dp[n-t[a[i]]]==1)
            {
                cout<<a[i];
                n=n-t[a[i]];
                break;
            }
        }
 //  cout<<endl;
    }
    return 0;
}
