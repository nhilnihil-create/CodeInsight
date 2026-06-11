#include<bits/stdc++.h>
using namespace std;
int k,a[100001],a1,b[2000001],b1=1,b2=9;
int main()
{
	memset(a,0x3f,sizeof(a));
	scanf("%d",&k);
	for(int i=1;i<10;i++)b[i]=a[i]=i;
	while(b1<=b2)
	{
		for(int i=0;i<10;i++)if(a[(b[b1]*10+i)%k]>a[b[b1]]+i)a[b[++b2]=(b[b1]*10+i)%k]=a[b[b1]]+i;
		++b1;
	}
	printf("%d",a[0]);
	return 0;
}