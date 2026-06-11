#include <bits/stdc++.h>
using namespace std;
const int N=2000+5;
int n,cnt;
long long sum;
int ans[N*N],num[N];
bitset<N*N> bt;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&num[i]),sum+=num[i];
	bt[0]=1;
	for(int i=1;i<=n;i++) bt=bt|bt<<num[i];
	for(int i=1;i<=sum;i++)
		if(bt[i]) ans[++cnt]=i;
	if(cnt%2==1) printf("%d",ans[(cnt+1)/2]);
	else printf("%d",ans[cnt/2]);
	return 0;
}