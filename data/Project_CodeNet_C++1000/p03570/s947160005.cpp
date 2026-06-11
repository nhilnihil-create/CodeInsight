#include <bits/stdc++.h>
using namespace std;
int freq[200005],dp[200005],i,j;
unordered_map<int,int> best;
#define get(k) (best.find(k)!=best.end()?best[k]:dp[i-1])
int main(){
	ios_base::sync_with_stdio(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();++i)
		freq[i+1]=freq[i]^(1<<(s[i]-'a'));
	for(best[0]=0,i=1;i<=s.size();++i){
		for(dp[i]=1+get(freq[i]),j=26;j--;dp[i]=min(dp[i],1+get(freq[i]^(1<<j))));
		if(best.find(freq[i])==best.end() || best[freq[i]]>dp[i]) best[freq[i]]=dp[i];
	}
	cout<<dp[s.size()];
}