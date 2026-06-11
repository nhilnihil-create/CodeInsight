#include<bits/stdc++.h>
using namespace std;
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
}*/
int n,k,a[1000000];
int dp[1000000];
int f(int i)
{
    if(i==(n-1)) return 0;
    if(i>=n) return INT_MAX;
    if(dp[i]!=-1) return dp[i];
    int right=INT_MAX;
    for(int j=1;j<=k;j++)
    {
    if((i+j)<n)
    {
    right=min(right,abs(a[i]-a[i+j])+f(i+j));
    }
    }
    return dp[i]=right;
}
void solve()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<f(0);
}
int main()
{
    fast_io;
    solve();
}
