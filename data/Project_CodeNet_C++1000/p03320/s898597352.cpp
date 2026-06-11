#include<bits/stdc++.h>
using namespace std;
int cc,tt;
long long a[10000],b[10000];
int s(long long a){int t=0;while(a)t+=a%10,a/=10;return t;}
int main()
{
	long long pw=1;
	for(int i=1;i<=15;i++)
	{
		for(int j=1;j<140;j++)if(j*pw!=1)a[++cc]=j*pw-1; 
		pw=pw*10;
	}
	sort(a+1,a+cc+1);cc=unique(a+1,a+cc+1)-a-1;
	for(int i=1;i<=cc;i++)if(a[i]<=1e15)
	{
		bool f=1;
		for(int j=i+1;j<=cc;j++)if(a[j]<=1e15)if(a[i]*s(a[j])>a[j]*s(a[i])){f=0;break;}
		if(f==1)b[++tt]=a[i];
	}
	int k;scanf("%d",&k);
	for(int i=1;i<=k;i++)printf("%lld\n",b[i]);
	return 0;
}