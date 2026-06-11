/*
    Author: aksayushx
*/
#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define all(a) a.begin(),a.end()
#define mp make_pair
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef long double ld;

/*
void compute()
{
	fac[0]=1;
	for(ll i=1;i<=10000;i++)
	fac[i]=(i*fac[i-1])%mod;
}
ll power(ll x, ll y)  
{  
    ll res = 1; 
    x = x % mod;
    while (y > 0)  
    {  
        if (y & 1)  
            res = (res*x) % mod;  
        y = y>>1; 
        x = (x*x) % mod;  
    }  
    return res;  
} 
ll modInverse(ll n) 
{ 
    return power(n, mod-2); 
}
ll nCr(ll n,ll r) 
{ 
    if (r == 0) 
        return 1; 
    return (fac[n] * modInverse(fac[r]) % mod * modInverse(fac[n - r]) % mod) % mod; 
}*/ 

int n,k;
vector<int> a;
vector<int> dp;
int optimal(int stones)
{
    if(dp[stones]!=-1)
    return dp[stones];
    int i=0;
    while(a[i]<=stones && i<n)
    {
        int moves=1+optimal(stones-a[i]);
        if(moves%2==1)
        {
            dp[stones]=moves;
            return dp[stones];
        }
        i++;
    }
    dp[stones]=0;
    return dp[stones];
}
void aksayushx()
{
    cin>>n>>k;
    a.resize(n);
    dp.resize(k+1,-1);
    for(int i=0;i<n;i++)
    cin>>a[i];
    int win=optimal(k);
    if(win%2==1)
    cout<<"First";
    else
    cout<<"Second";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test=1;
    //cin>>test;
    while(test--)
        aksayushx();
    return 0;
}
