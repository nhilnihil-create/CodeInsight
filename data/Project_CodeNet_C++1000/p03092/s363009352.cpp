#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
ll n,va,vb,a[5050],pos[5050],dp[5050][10010];
int main() {
	memset(dp,7,sizeof(dp));
	read(n);read(va);read(vb);
	for(int i=1;i<=n;i++){
		read(a[i]);
		pos[a[i]] = i;
	}
	dp[0][1] = 0;
	for(int i=1;i<=n;i++){
		ll cmin = 1e18;
		for(int j=1;j<=n*2+1;j++){
			if(j&1){
				cmin = min(cmin,dp[i-1][j]);
				cmin = min(cmin,dp[i-1][j-1]);
			}
			if(pos[i]*2 < j)dp[i][j] = cmin+va;
			if(pos[i]*2 == j)dp[i][j] = cmin;
			if(pos[i]*2 > j)dp[i][j] = cmin+vb;
		}
	}
	ll ans = 1e18;
	for(int j=1;j<=n*2+1;j++)ans = min(ans,dp[n][j]);
	cout<<ans<<endl;
	return 0;
}
