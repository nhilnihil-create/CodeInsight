#include<bits/stdc++.h>
#include<math.h>
#define N 100005
#define K 200005
#define MOD (int)1e9+7
#define ll long long int
using namespace std;
double dp[305][305][305];

int n;
double dfs(int a,int b,int c)
{
    if(a+b+c==0)
    {
        return 0.0;
    }
    if(dp[a][b][c]>-0.5)
    {
        return dp[a][b][c];
    }
    double ans=0.0;
     double ks=(double)n/(a+b+c);
    if(a)
    {
         double pr=(double)a/(a+b+c);
        ans+=(dfs(a-1,b,c)+ks)*pr;
    }
     if(b)
    {
         double pr=(double)b/(a+b+c);
        ans+=(dfs(a+1,b-1,c)+ks)*pr;
    }
     if(c)
    {
         double pr=(double)c/(a+b+c);
        ans+=(dfs(a,b+1,c-1)+ks)*pr;
    }
    return dp[a][b][c]=ans;
}
int main() {
   
    cin>>n;
    vector<int> cnt(4);
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        cnt[a]++;
    }
     for(int c=n;c>=0;c--)
    {
        for(int b=n;b>=0;b--)
        {
            for(int a=n;a>=0;a--)
            {
                dp[a][b][c]=-1.0;
            }
        }
    }
    double ans=dfs(cnt[1],cnt[2],cnt[3]);
    cout<<setprecision(10)<<fixed<<ans<<endl;
}