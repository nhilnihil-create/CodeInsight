#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
#define inf 1000000007
#define LINF 1000000000000000007LL
#define ll long long
using namespace std;
int dp[1<<26];
int val[214514];
int ans[214514];
signed main(){
	string str;
	cin>>str;
	int n = str.size();
	for(int i=1;i<=n;i++){
		int cur = str[i-1] - 'a';
		val[i] = val[i-1] ^ ( 1 << cur ) ;
	}
	for(int i=0; i < (1<<26) ; i++){
		dp[i] = inf;
	}
	dp[0] = 0;
	for(int i=1;i<=n;i++){
		vector<int> v;
		int cur = val[i];
		v.pb( dp[ cur ] );
		for(int j=0;j<26;j++){
			v.pb( dp[ cur ^ (1<<j) ] );
		}
		sort(v.begin(),v.end());
		ans[i] = v[0] + 1 ;
		//cout<<ans[i]<<endl;
		dp[ cur ] = min( dp[cur], ans[i] );
	}
	cout<<ans[n]<<endl;
	return 0;
}