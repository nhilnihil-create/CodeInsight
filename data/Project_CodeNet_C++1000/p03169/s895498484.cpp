																//  SMOKE SHISHA PLAY FIFA  // 
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pll pair<ll,ll>
#define MP make_pair
#define ff first
#define ss second
#define PB push_back
#define mod 1000000007
#define lp(i,start,end) for(ll i=start;i<=end;i++) 
#define deb1(a) cout<<#a<<" = "<<(a)<<endl;
#define deb2(a,b) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<endl;
#define deb3(a,b,c) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<endl;
double dp[301][301][301];
ll N,vis[301][301][301];


double solve(ll x,ll y,ll z){
	
	if(vis[x][y][z]) 
		return dp[x][y][z];
	
	vis[x][y][z] = 1;

	if(x == 0 && y == 0 && z == 0) 
		return dp[x][y][z] = 0;

	ll sum = x + y + z;
	double tot = (N - sum)/(double)(sum);

	if(x != 0) 
		tot += x*((solve(x-1,y,z) + 1)/(double)(sum));
	if(y != 0) 
		tot += y*((solve(x+1,y-1,z) + 1)/(double)(sum));
	if(z != 0) 
		tot += z*((solve(x,y+1,z-1) + 1)/(double)(sum));

	return dp[x][y][z] = tot;

}

ll modu(ll a, ll b)
{
	ll ans =1;
	while(b>0)
	{
		if(b&1)
		ans = (ans*a)%mod;
		b/=2;
		a = (a*a)%mod;
	}
	return ans;
}

int main(){

	ll a[4] = {0};

	cin >> N;

	for(ll i = 1;i<=N;i++){
		ll x;
		cin >> x;
		a[x]++;
	}

	printf("%.9lf\n",solve(a[1],a[2],a[3]));

	return 0;
}