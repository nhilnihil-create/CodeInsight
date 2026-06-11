#include <bits/stdc++.h>
#define ll  long long int
#define PB push_back
#define M  1000000007
#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define sz size()
#define endl "\n"
#define vll vector<ll>
#define vii vector<int> 
#define mll map<ll,ll>
#define frl(i,a,n) for(ll i=a;i<n;i++) 
#define cases ll t;cin>>t;while(t--)
using namespace std;
//vector<ll> adj[200005];
//vll v(200005,0);
//vector<bool> vis(200005,0);
bool isPrime(long long n) 
{
 	if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
}
ll lcm(ll a,ll b)
{
	ll x=a*b;
	return (x/gcd(a,b));
}
ll logint(ll a,ll b)
{
	ll i=0;
	ll k=1;
	while(a>k)
	{
		i++;
		k=pow(b,i);
		//cout<<i<<" ";
	}
	return i-1;
}
void printDivisors(ll n, vector<ll> &v1)
{
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
            {
                v1.PB(i);
            }
            else
            {
                v1.PB(i);
                v1.PB(n / i);
            }
        }
    } 
}
void solve()
{
	ll n,k;cin>>n>>k;
	ll a[n];
	frl(i,0,n)
	cin>>a[i];
	vii dp(k+1,-1);
	dp[0]=0;
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[j]<=i)
			{
				if(dp[i-a[j]]==0)
				{
					dp[i]=1;break;
				}
			}
		}
		if(dp[i]==-1)
		dp[i]=0;
	}
	if(dp[k])
	cout<<"First"<<endl;
	else
	cout<<"Second"<<endl;
}
	
int main ()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
//	cases
	{
		solve();
	}
}