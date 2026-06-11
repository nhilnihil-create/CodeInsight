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
vector<long long int>v[100007];
long long int dp[100007];
bool visited[100007];
void visit(long long int i)
{
    //cout<<i<<endl;
    visited[i]=1;
    dp[i]=0;
    for(auto x:v[i])
    {
        if(visited[x]==false)
        {
            visit(x);
        }
        dp[i]=max(dp[i],1+dp[x]);
    }
}
void solve()
{
    long long int n,m;cin>>n>>m;
    while(m--)
    {
        long long int a,b;cin>>a>>b;
        v[a].push_back(b);
    }
    for(long long int i=0;i<=n;i++)
    visit(i);
    long long int ans=INT_MIN;
    for(long long int i=0;i<=n;i++)
    {
        //cout<<dp[i]<<" ";
        ans=max(ans,dp[i]);
    }
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
