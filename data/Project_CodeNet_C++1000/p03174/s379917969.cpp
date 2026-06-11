#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define ld long double
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define rloop(i,a,b) for(ll i=a;i>b;i--)
const ll inf=1e9+7;
ll addself(ll x)
{
	if(x<inf)return x;
	else
	return (x+inf)%inf;
}
int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0);

ll n;
cin>>n;
ll mask[n]={0},ai,b;
	loop(i,0,n)
	{
		loop(j,0,n)
		{
			cin>>ai;
			mask[i]|=ai<<j;
		}
	
	}

	vector<ll>dp(1<<n); //2^n possible combinatons
	dp[0]=1; // 1 way to get 000...0
	loop(i,0,(1<<n)-1)
	{
		
		b=__builtin_popcount(i);// number of bit set to 1;
		loop(j,0,n)
		{
			if((mask[b]&(1<<j)) &&( !(i&(1<<j)) ))  // intersted pair && position not used
			{
				dp[i|(1<<j)]+=dp[i];
				dp[i|(1<<j)]=addself(dp[i|(1<<j)]);
			}
			
		}
	}

cout<<dp.back();	
	
}
