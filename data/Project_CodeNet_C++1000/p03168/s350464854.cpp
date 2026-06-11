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
double dp[3000][3000];
void solve()
{
    long long int n;cin>>n;
    double p[n];for(auto &x:p)cin>>x;
    
    dp[0][0]=1-p[0];dp[0][1]=p[0];
    for(long long int i=1;i<n;i++)
    {
        for(long long int j=0;j<=n;j++)
        {
            //head
            if(j>0)
            dp[i][j]+=p[i]*1.0*dp[i-1][j-1];
            //tail
            dp[i][j]+=(1-p[i])*dp[i-1][j];
        }
    }
    for(long long int i=0;i<0;i++)
    {
        for(long long int j=0;j<=n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    double ans=0.000;
    for(long long int i=n/2+1;i<=n;i++)
    ans+=dp[n-1][i];
    cout<<fixed<<setprecision(10)<<ans<<endl;
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
