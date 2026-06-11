#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);

const int N=410;
const ll inf=1e18;
ll dp[N][N],sz[N][N];
ll a[N],p[N];
int n;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<=n;++i)
		for(int j=0;j<=n;++j)
			dp[i][j]=inf;
	for(int i=0;i<n;++i)dp[i][i]=0;
	for(int i=1;i<=n;++i)p[i]=p[i-1]+a[i-1];
	for(int dist=1;dist<n;++dist)
		for(int st=0;st+dist<n;++st)
			for(int md=st;md<st+dist;++md)
				dp[st][st+dist]=min(dp[st][st+dist],dp[st][md]+dp[md+1][st+dist]+p[st+dist+1]-p[st]);
	cout<<dp[0][n-1]<<endl;
}
