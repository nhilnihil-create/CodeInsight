#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define modulo 1000000007
#define fast_io ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
using namespace std;
int a[21][21];
ll dp[1<<21]={0};
int main(){
	fast_io;
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cin>>a[i][j];
		}
	}
	dp[0]=1;
	for (int i = 0; i < (1<<n); ++i){
		int idx=__builtin_popcount(i);
		for (int j = 0; j < n; ++j){
			if(a[idx][j] && (!(i & (1<<j))))
				dp[i | (1<<j)]=(dp[i | (1<<j)]+dp[i])%modulo;
		}
	}
	cout<<dp[(1<<n)-1]<<"\n";
	return 0;
}