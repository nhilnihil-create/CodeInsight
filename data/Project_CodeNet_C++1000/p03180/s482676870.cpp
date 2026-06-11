#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(0)
#define scn(n) scanf("%d",&n)
#define lscn(n) scanf("%lld",&n)
typedef long long ll;
#define pri(n) printf("%d\n",n)
#define lpri(n) printf("%lld\n",n);
#define rep(i,st,ed) for(int i=st;i<ed;i++)
#define var(n) int n; scn(n)
#define F first
#define S second 
#define pb(n) push_back(n)
const int N=1e5+5;
const ll M=1e9+7;
const ll inf=1e18+5;


vector<ll> dp,pre;

void rec(int i,vector<int>& rest,ll score,int mask,int group)
{
	if(i == (int)rest.size())
	{
		dp[mask] = max(dp[mask],score+pre[group]);
		return;
	}
	// we have 2 possibilities
	rec(i+1,rest,score,mask,group); 	// do not consider this one
	rec(i+1,rest,score,mask^(1<<rest[i]),group^(1<<rest[i]));	// consider this one
}

int main()
{
	int n;
	scn(n);
	int m = 1<<n;
	pre.resize(m);
	vector<vector<ll>> a(n,vector<ll>(n));

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			lscn(a[i][j]);
		}
	}
	// preprocessing
	// pre[mask] stores the score of 1 group having elementa(as rabbits) corresponding to bitset in the mask
	for(int mask = 0;mask<m;mask++){
		for(int i = 0;i<n;i++){
			if(mask&(1<<i)){
				for(int j=i+1;j<n;j++){
					if(mask&(1<<j)){
						pre[mask]+=a[i][j];
					}
				}					
			}
		}			
	}
	// dp[mask] stores the best possbile score considering all the possible sets of bits in the mask
	dp.resize(m,-inf);
	dp[0] = 0;
	for(int mask=0;mask<m;mask++)
	{
		vector<int> rest;
		for(int i=0;i<n;i++)
		{
			if(!(mask&(1<<i)))
				rest.pb(i);
		}
		rec(0,rest,dp[mask],mask,0);
	}
	lpri(dp[m-1]);		// all the rabbit is taken	
}