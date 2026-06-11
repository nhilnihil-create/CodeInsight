#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

int n,a[100000];

int _abs(int a) {
	return a<0 ? -a : a;
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);

	sort(a,a+n);
	int mx=a[n-1]+1,ai=-1;
	for(int i=0;i<n-1;i++) {
		int v=max(a[i],a[n-1]-a[i]);
		if(v < mx) {
			mx=v; ai=i;
		}
	}
	printf("%d %d\n",a[n-1],a[ai]);

	return 0;
}