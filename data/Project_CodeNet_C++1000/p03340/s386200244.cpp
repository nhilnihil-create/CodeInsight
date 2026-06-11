#include <bits/stdc++.h>
using namespace std;
const int N=300000;
int a[N],n;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	long long j=0,tmp=0,sum=0,num=0;
	for (long long i=1;i<=n;i++)
	{
		while(j<n&&(tmp^a[j+1])==(sum+a[j+1])) tmp^=a[++j],sum+=a[j];
 		tmp^=a[i];sum-=a[i];
		num+=j-i+1;
//		printf("%d %d/",i,j);
	}
	printf("%lld\n",num); 
	return 0;
}