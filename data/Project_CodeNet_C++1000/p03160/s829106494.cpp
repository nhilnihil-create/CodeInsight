//_Krenil_Bhikadiya_

#include<bits/stdc++.h>
#define MAX_SPEED ios_base::sync_with_stdio(false); cin.tie(NULL);
#define max(a,b) (a<b?b:a) 
#define min(a,b) (a>b?b:a) 
#define ll long long
#define ld long double
#define llu unsigned long long int
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define umap unordered_map
#define uset unordered_set
#define rep(i,a,n) for(int i=(int)a;i<(int)n;i++)
#define rev(i,n,a) for(int i=(int)n;i>=(int)a;i--)
#define pb push_back
#define ff first
#define ss second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define endl "\n"
const int INF  = 1e9;
const llu INFM = 1e18;
const int mod  = INF+7;
using namespace std;


int gcd(int A,int B)
{
	if(A==0) return B;

	return gcd(B%A,A);
}

int lcm(int A,int B)
{
	return ( A*B / gcd(A,B) );
}

ll pwr(ll A,ll B,ll P)
{
	ll RES = 1; A %= P;

	while(B>0)
	{
		if(B&1) RES = RES * A % P;
		A = A * A % P;
		B >>= 1;
	}

	return RES;
}

ll modInv(ll A,ll M)
{
	return pwr(A,M-2,M);
}

bool isPrime(int N)
{
	if(N==1) return false;

	for(int i=2;i*i<=N;i++)
	{
		if(N%i==0) return false;
	}

	return true;
}

int a[100001],n;
int dp[100001];

int rec(int i)
{
	if(i>=n) return 0;
	if(dp[i]!=-1) return dp[i];
	int c1=INT_MAX;
	if((i+1)<=n)c1=abs(a[i]-a[i+1])+rec(i+1);
	int c2=INT_MAX;
	if((i+2)<=n)c2=abs(a[i]-a[i+2])+rec(i+2);

	return dp[i]=min(c1,c2);
}

int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	MAX_SPEED
	
	int test=1; //cin>>test;
	while(test--)
	{
		cin>>n;

		memset(dp,-1,sizeof dp);

		rep(i,1,n+1) cin>>a[i];

		cout<<rec(1)<<endl; 
	}
}