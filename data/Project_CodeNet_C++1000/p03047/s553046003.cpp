//  Mayank Agarwal
//  IIIT Hyderabad



#include<bits/stdc++.h>
using namespace std;
const long long int M = 1000000007; 
#define ll long long int
#define ld double
#define pb push_back
#define mp make_pair
ll power(ll x, ll y,  ll p) 
{ 
    ll res = 1;      
    x = x % p;   
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1;x = (x*x) % p; 
    } return res%p; 
} 
ll modinver(ll a,ll b)
{
    return (power(a,1,M)*power(b,M-2,M))%M;
}
void SieveOfEratosthenes(int n) 
{   
    bool prime[10005]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
} 
ll dp[100][100];
ll ncr(ll n,ll k)
{
	if(n==k || k==0)
	{
		return 1;
	}
	if(dp[n][k]!=-1)
	{
		return dp[n][k];
	}
	dp[n][k]=ncr(n-1,k)+ncr(n-1,k-1);
	return dp[n][k];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n,k;
    cin>>n>>k;
    // for (int i = 0; i <=54; ++i)
    // {
    // 	for (int j = 0; j<=54; ++j)
    // 	{
    // 		dp[i][j]=-1;
    // 	}
    // }
    // cout<<ncr(n,k);
    cout<<n-(k-1)<<'\n';
    // cout<<dp[n][k];
}
