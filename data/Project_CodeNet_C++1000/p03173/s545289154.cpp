#include <bits/stdc++.h>
#include <numeric>
#define M 1000000007
#define inf 1e18+1
#define pb push_back
// #define mp make_pair
#define forz(i,s,n) for(lli i=s;i<n;i++)
#define fore(i,n,s) for(lli i=n;i>=s;i--)
#define binod ios_base ::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long int lli;
//typedef pair<long long int, long long int> pll;
typedef unsigned long long int ull;
using namespace std;

lli recpow(lli x, lli n, lli mod)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0) //n is even
        return recpow((x * x) % mod, n / 2, mod);
    else //n is odd
        return (x * recpow((x * x) % mod, (n - 1) / 2, mod)) % mod;
}

const int nax=402;
lli dp[nax][nax];
lli n, a[nax], p[nax],ps;

lli sum(lli i,lli j)
{
    if(i>j)
    return 0;
    if(i-1<0)
    return p[j];
    return p[j]-p[i-1];
}

lli func(lli i, lli j)
{
    if(i==j)
    return dp[i][j]=0;
    if(j==i+1)
    return dp[i][j]=a[i]+a[j];
    if(dp[i][j]!=-1)
    return dp[i][j];
    dp[i][j]=inf;
    forz(i1,i,j)
    dp[i][j]=min(dp[i][j],func(i,i1)+func(i1+1,j)+sum(i,i1)+sum(i1+1,j));
    return dp[i][j];
}

//code begins here
int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    binod
    //sieve();
    cin>>n;
    ps=0;
    forz(i,0,n)
    {
        cin>>a[i];
        ps+=a[i];
        p[i]=ps;
    }
    forz(i,0,nax)
    forz(j,0,nax)
    dp[i][j]=-1;
    cout<<func(0,n-1);
    return 0;
}