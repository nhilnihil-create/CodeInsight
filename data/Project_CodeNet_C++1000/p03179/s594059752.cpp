#include <bits/stdc++.h>

#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 1e9+7;
const ll INF = (ll)1<<62;
const double PI = 3.14159265359;

const int maxn = 3005; 
ll dp[maxn][maxn];

int main(){
	int n;
	ll pre[maxn];
	string s;
	cin>>n>>s;

	dp[1][1] = 1;
	pre[0] = 0;
	pre[1] = 1;

	for(int len=2;len<=n;len++){
		for(int curr=1;curr<=len;curr++){
			dp[len][curr] = 0;
			/*for(int last=1;last<len;last++){
				if(s[len-2] == '<' && curr>last)
					dp[len][curr] = (dp[len][curr]+dp[len-1][last])%MOD;
				if(s[len-2] == '>' && curr<=last)
					dp[len][curr] = (dp[len][curr]+dp[len-1][last])%MOD;

				if(dp[len][curr] < 0)
					dp[len][curr] += MOD;
			}*/

			if(s[len-2] == '<')
				dp[len][curr] = pre[curr-1];
			else
				dp[len][curr] = pre[len-1]-pre[curr-1];
		}
		pre[0] = 0;
		for(int i=1;i<=len;i++){
			pre[i] = (pre[i-1]+dp[len][i])%MOD;
			if(pre[i] < 0)
				pre[i] += MOD;
		}
	}

	ll ans = 0;
	for(int i=1;i<=n;i++){
		ans = (ans+dp[n][i])%MOD;
		if(ans < 0)
			ans += MOD;
	}
	cout<<ans<<"\n";
	return 0;
}