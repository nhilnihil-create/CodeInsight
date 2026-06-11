#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+5;
typedef long long LL;
int a[maxn]; int b[maxn]; int base[60]; int c[maxn];
int main(void)
{
	for(int i=0;i<31;i++) base[i]=(1<<i);
	int n; scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	int res=0;
	for(int i=0;i<30;i++)
	{
		for(int j=1;j<=n;j++) b[j]=c[j]%base[i+1];
		sort(b+1,b+1+n);
		LL cnt=0;
		for(int j=1;j<=n;j++)
		{
			int l,r;	
			l=lower_bound(b+1,b+1+n,base[i]-(a[j]%base[i+1]))-b;
			r=upper_bound(b+1,b+1+n,base[i+1]-(a[j]%base[i+1])-1)-b;
			r--;
			if(r-l+1>=0) cnt+=r-l+1;
			
			l=lower_bound(b+1,b+1+n,base[i]+base[i+1]-(a[j]%base[i+1]))-b;
			r=upper_bound(b+1,b+1+n,base[i+2]-2-(a[j]%base[i+1]))-b;
			r--;
			if(r-l+1>=0) cnt+=r-l+1;
		}
		if(cnt&1) res|=base[i];
	}
	printf("%I64d\n",res);
	return 0;
}