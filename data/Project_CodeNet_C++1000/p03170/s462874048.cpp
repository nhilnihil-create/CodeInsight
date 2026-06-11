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

const int nax=1e5+4;
int n,k, mini;
int dp[nax]; 
int a[102];

bool func(lli x)
{
    //cout<<x<<" ";
    if(x<0)
    return 1;
    if(x<mini)
    return dp[x]=0;
    if(dp[x]!=-1)
    return dp[x];

    forz(i,0,n)
    if(func(x-a[i])==0)
    return dp[x]=1;

    return dp[x]=0;
}

//code begins here
int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    binod
            //sieve();
            //cout  << "hgfjhg";
    forz(i,0,nax) dp[i]=-1;
    cin>>n>>k;
    forz(i,0,n) cin>>a[i];

    mini=*min_element(a,a+n);

    // forz(i,0,mini)
    // dp[i]=0;
    // forz(i,0,n)
    // forz(j,a[i],k+1)
    // {
    //     if(dp[j-a[i]]==0)
    //     dp[j]=1;
    //     else  
    //     dp[j]=0;
    // }
    
    if(func(k))
    cout<<"First";
    else  cout<<"Second";

    return 0;
}