#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct block{
	int w,s,v;
	void input(){
		scanf("%d%d%d",&w,&s,&v);
	}
	bool operator<(block a){
		return w+s<a.w+a.s;
	}
}bk[1005];
int n;
ll dp[20005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)bk[i].input();
	sort(bk+1,bk+n+1);
	for(int i=1;i<=n;i++)for(int j=bk[i].s;j>=0;j--)dp[j+bk[i].w]=max(dp[j+bk[i].w],dp[j]+bk[i].v);
	printf("%lld\n",*max_element(dp,dp+20005));
	return 0;
}