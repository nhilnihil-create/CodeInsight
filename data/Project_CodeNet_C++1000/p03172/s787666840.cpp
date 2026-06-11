#include <bits/stdc++.h>

using namespace std;

const int N = 105, K = 1e5 + 5, MOD = 1e9 + 7;
int n, p, dp[N][K], prefix[N][K], a[N];

inline int add(int a, int b){
	a += b;
	if(a >= MOD)a -= MOD;
	return a;
}

inline int sub(int a, int b){
	a -= b;
	if(a < 0)a += MOD;
	return a;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n>>p;
	for(int i=1;i<=n;++i)cin>>a[i];

	for(int i=0;i<=n;++i)dp[i][0] = prefix[i][0] = 1;
	for(int j=0;j<=p;++j)prefix[0][j] = 1;

	for(int i=1;i<=n;++i)
		for(int j=1;j<=p;++j){
			// coefficient of x^j is prefix[i - 1][j - a[i] : j];

			int first = (j - a[i] - 1 >= 0)? prefix[i - 1][j - a[i] - 1] : 0;
			int last = prefix[i - 1][j];
			dp[i][j] = add(dp[i][j], sub(last, first));
			prefix[i][j] = add(prefix[i][j - 1], dp[i][j]);
		}

	cout<<dp[n][p]<<"\n";
	return 0;
}