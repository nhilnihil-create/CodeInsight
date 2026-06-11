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

const int N=1010,mod=1e9+7;
int n,m;
string f[N];
int dp[N][N];

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<n;++i)cin>>f[i];
	dp[0][0]=f[0][0]=='.';
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if(f[i][j]!='#'){
				dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
				dp[i][j+1]=(dp[i][j+1]+dp[i][j])%mod;
			}
	cout<<(f[n-1][m-1]=='.')*dp[n-1][m-1]<<endl;
}
