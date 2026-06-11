#include<bits/stdc++.h>
using namespace std;
// << left shift *2 and >>right shift /2
long long int mod97=1000000007;
double pi=3.1415926536;
bool comp(pair<long long int,long long int>a,pair<long long int,long long int>b)
{
    if(a.first==b.first)
    {
        if(a.second<=b.second)
        return true;
        else
        return false;
    }
    if(a.first>b.first)
    return true;
    else return false;
}
bool rev(long long int a,long long int b)
{
    if(a>b)return true;
    else return false;
}
bool compa(pair<string,pair<int,int>>a,pair<string,pair<int,int>>b)
{
    if(a.first==b.first)
    {
        if(a.second.first>b.second.first)
        return true;
        else
        return false;
    }
    if(a.first<b.first)
    return true;
    else 
    return false;
}
long long int gcd(long long int bdda,long long int chota)
{
    if(chota==0)
        return bdda;
    return gcd(chota,bdda%chota);
}

void solve()
{
    long long int n,m;cin>>n>>m;
    char c[n][m];
    for(long long int i=0;i<n;i++)for(long long int j=0;j<m;j++)cin>>c[i][j];
    long long int dp[n][m];
    for(long long int i=0;i<n;i++)
    {
        for(long long int j=0;j<m;j++)
        {
            if(i==0 && j==0)
            dp[i][j]=1;
            else if(i==0)
            {
                if(c[i][j]=='#')
                dp[i][j]=0;
                else
                dp[i][j]=dp[i][j-1];
            }
            else if(j==0)
            {
                if(c[i][j]=='#')
                dp[i][j]=0;
                else
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                if(c[i][j]=='#')
                dp[i][j]=0;
                else
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod97;
            }
        }
    }
    for(long long int i=0;i<0;i++)
    {
        for(long long int j=0;j<m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    long long int ans=dp[n-1][m-1];
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;    
    t=1;
    //cin>>t;long long int temp=t;
    while(t--)
    {
        //cout<<"Case "<<temp-t<<": ";
        solve();
    }
}
