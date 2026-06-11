/*input
byebye
*/
#include <bits/stdc++.h>
using namespace std;
int freq[200005],n,dp[200005],i;
unordered_map<int,int> best;
inline int get(int k){
	return best.find(k)!=best.end()?best[k]:dp[i-1];
}
int main(){
	#ifdef ONLINE_JUDGE
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	#endif
	long long q,m,k,h,ans=0,sum=0,p,x,y;
	string s;
	cin>>s;
	n=s.size();
	s='.' + s;
	for(int i=1;i<=n;++i)
		freq[i]=freq[i-1]^(1<<(s[i]-'a'));
	for(best[0]=0,i=1;i<=n;++i){
		dp[i]=1+get(freq[i]);
		for(int j=0;j<26;++j)
			dp[i]=min(dp[i],1+get(freq[i]^(1<<j)));
		if(best.find(freq[i])==best.end()) best[freq[i]]=dp[i];
		else best[freq[i]]=min(best[freq[i]],dp[i]);
	}
	cout<<dp[n];
}