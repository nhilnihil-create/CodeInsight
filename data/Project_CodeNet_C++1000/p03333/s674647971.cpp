#include<bits/stdc++.h>
#define N 100009
using namespace std;
 
int n,a[N],b[N];
int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d%d",&a[i],&b[i]);
	n++;
	sort(a+1,a+n+1); sort(b+1,b+n+1);
	long long ans=0;
	for (int i=1; i<=n; i++) ans+=max(0,a[n-i+1]-b[i]);
	printf("%lld\n",ans*2); 
	return 0;
}