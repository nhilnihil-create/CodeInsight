#include<bits/stdc++.h>
using namespace std;
#define D double
#define lli long long int
#define testcase int t;cin>>t;while(t--)
#define fast_io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define P pair<int,int>
/*bool isprime(lli n)
{
    if(n==1) return 0;
    for(lli i=2;i<=n/2;i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}
bool issemiprime(lli n)
{
    for(int i=2;i<n;i++)
    {
        if(isprime(i)&&isprime(n/i)&&n%i==0&&i!=n/i){
            return 1;
        }
    }
    return 0;
}
lli extendedgcd(lli q,lli r1,lli r2,lli r,lli s1,lli s2,lli s,lli t1,lli t2,lli t)
{
if(r2==0) return r1;
	r1=r2;
        r2=r;
        s1=s2;
        s2=s;
        t1=t2;
        t2=t;
        q=r1/r2;
        r=r1%r2;
        s=s1-(s2*q);
        t=t1-(t2*q);
return extendedgcd(q,r1,r2,r,s1,s2,s,t1,t2,t);
}
lli gcd(lli a,lli b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
void SOE()
{
    for(lli i=2;i<=100000;i++)
    {
        if(sieve[i]) continue;
        for(lli x=i;x<=100000;x+=i)
        {
            sieve[x]+=1;
        }
    }
}*/
/*bool func(pair<int,int> a,pair<int,int> b)
{
    return a.first<b.first;
}
int dfs(vector<vector<int>> g,int n)
{
    if(g[n].size()==0) return 0;
    if(dp[n]!=-1) return dp[n];
    for(auto x:g[n])
    {
        dp[n]=max(dp[n],1+dfs(g,x));
    }
    return dp[n];
}*/
void solve()
{
    lli n;
    cin>>n;
    double h[n];
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    D dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<n+1;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0)
            {
                dp[i][j]=(1.0-h[i-1])*dp[i-1][j];
            }
            else{
                dp[i][j]=(h[i-1]*dp[i-1][j-1])+((1.0-h[i-1])*dp[i-1][j]);
            }
        }
    }
    double res=0.0;
    for(int i=n;i>(n/2);i--)
    {
        res+=dp[n][i];
    }
    cout<<fixed<<setprecision(10)<<res;
}
int main()
{
    fast_io;
    solve();
}
