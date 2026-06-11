#include <bits/stdc++.h>

const int maxn=1<<18|1;

int n,ALL;
int a[maxn];
int ans[maxn];

int main (){
	scanf("%d",&n);
	ALL=(1<<n)-1;
	for (int S=0;S<=ALL;S++)
		scanf("%d",&a[S]);
	for (int S=1,now;S<=ALL;S++){
		now=a[S];
		for (int S0=S;S0;S0=(S0-1)&S){
			ans[S]=std::max(ans[S],now+a[S^S0]);
			now=std::max(now,a[S^S0]);
		}
	}
	for (int i=1;i<=ALL;i++)
		printf("%d\n",ans[i]=std::max(ans[i],ans[i-1]));
	return 0;
}
