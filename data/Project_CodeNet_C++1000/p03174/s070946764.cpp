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

const int N=22,M=(1<<N),mod=1e9+7;
const ll inf=1e18;
ll dp[N][M];
ll a[N][N];
int n;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			cin>>a[i][j];
	dp[0][0]=1;
	for(int i=0;i<n;++i)
		for(int j=0;j<(1<<n);++j)
			if(__builtin_popcount(j)==i)
				for(int k=0;k<n;++k)
					if(!((1<<k)&j)&&a[i][k])
						dp[i+1][j|(1<<k)]=(dp[i+1][j|(1<<k)]+dp[i][j])%mod;
	cout<<dp[n][(1<<n)-1]<<endl;
}
