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

const int N=110,K=100100,mod=1e9+7;
int a[N];
int dp[N][K];
int n,k;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>k;
	for(int i=0;i<n;++i)cin>>a[i];
	dp[0][0]=1;
	dp[0][1]=-1;
	for(int i=0;i<=n;++i)
		for(int j=0;j<=k;++j){
			dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
			if(j+a[i]+1<=k)dp[i+1][j+a[i]+1]=(dp[i+1][j+a[i]+1]-dp[i][j]+mod)%mod;
			dp[i][j+1]=(dp[i][j+1]+dp[i][j])%mod;
		}
	cout<<dp[n][k]<<endl;
}
