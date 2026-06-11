#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

ll c[200010],dp[200010],ch[200010];
int main() {
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>c[i];
	}
	dp[0]=1;
	for(ll i=1;i<=n;i++){
		if(c[i-1]!=c[i]){
			ch[c[i-1]]=i-1;
			if(ch[c[i]]!=0){
				dp[i]+=dp[ch[c[i]]];
			}
		}
		dp[i]+=dp[i-1];
		dp[i]%=inf;
	}
	cout << dp[n];
	// your code goes here
	return 0;
}