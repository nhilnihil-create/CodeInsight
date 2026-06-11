#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;
int n,c[200009],dp[200009],c2[200009],num,pn[200009];
vector<int>pos[200009];
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",c+i);
	for(int i=0;i<n;) {
		c2[num++]=c[i];
		pos[c[i]].push_back(num-1);
		int j;
		for(j=i+1;j<n&&c[j]==c[i];j++);
		i=j;
	}
	dp[0]=1;
	pn[c2[0]]++;
	for(int i=1;i<num;i++) {
		dp[i]=dp[i-1];
		if(pn[c2[i]]-1>=0) {
			dp[i]=(dp[i]+dp[pos[c2[i]][pn[c2[i]]-1]])%mod;
		}
		pn[c2[i]]++;
	}
	printf("%d\n",dp[num-1]);
	return 0;
}