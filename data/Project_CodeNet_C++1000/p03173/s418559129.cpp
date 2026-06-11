#include <bits/stdc++.h>
#define lli long long int
#define vec2 vector<vector<lli>> 
#define fio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define FRE freopen("explicit.in","r",stdin);freopen("explicit.out","w",stdout)
#define pll pair <lli,lli>
#define vll vector <lli>
#define vpll vector <pll>
#define f first
#define s second
#define pb push_back
#define priq priority_queue
#define unm unordered_map
#define pf push_front
#define minii LLONG_MAX
#define all(x) x.begin(), x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define ld double
#define eb emplace_back
const long double pi = 3.1415926535898;
const lli mod=1e9+7;
//const lli mod=100000000;
using namespace std;
lli lcm (lli a, lli b) {return ((a*b)/__gcd(a,b));}
lli modpower (lli a,lli b)
{
    if(b==0) return 1;
    lli c=modpower(a,b/2)%mod;
    if (b%2) return (((a*c)%mod)*c)%mod;
    else return (c*c)%mod;
}
lli power (lli a,lli b)
{
    if(b==0) return 1;
    lli c=power(a,b/2);
    if (b%2) return (a*c*c);
    else return c*c;
}
bool prime (lli k)
{
    if (k==1||k==0) return 0;
    bool flag=1;
    lli a=sqrt(k);
    for (int i=2;i<=a;i++)
    {
        if (k%i==0)
        {flag=0;break;}
    }
    return flag;
}
lli sieve (int n)
{
    bool qrr[n+1];
    for (int i=0;i<=n;i++)
    qrr[i]=1;qrr[0]=0;qrr[1]=0;
    for (int i=2;i*i<=n;i++)
    {
        if (qrr[i]==1)
        {
            for (int j=2*i;j<=n;j+=i)
            {qrr[j]=0;}
        }
    }
    return 0;
}
lli n;
lli a[401];
lli pre[401];
lli dp[401][401];
lli find(lli l,lli r)
{
    if (l>=r)
    return 0;
    if (dp[l][r]!=-1)
    return dp[l][r];
    dp[l][r]=1e18;
    for (int i=l;i<=r-1;i++)
    {
        dp[l][r]=min(dp[l][r],find(l,i)+find(i+1,r)+pre[r]-pre[l-1]);
    }
    return dp[l][r];
}
int main()
{
    fio;
    cin>>n;
    a[0]=0;
    pre[0]=0;
    mem(dp,-1);
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        pre[i]=a[i]+pre[i-1];
        dp[i-1][i]=a[i-1]+a[i];
    }
    find(1,n);
    cout<<dp[1][n];
    return 0;
}