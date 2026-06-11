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
	for (int i=0;i<n;i++)
		for (int S=1;S<=ALL;S++)
			if (S>>i&1){
				ans[S]=std::max(ans[S],a[S]+a[S^(1<<i)]);
				a[S]=std::max(a[S],a[S^(1<<i)]);
			}
	for (int i=1;i<=ALL;i++)
		printf("%d\n",ans[i]=std::max(ans[i],ans[i-1]));
	return 0;
}
