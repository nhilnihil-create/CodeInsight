#include<bits/stdc++.h>
using namespace std;
#define ll long long
int cc,tt;ll pw=1,a[10005],b[10005];
int S(ll a){int r=0;while(a)r+=a%10,a/=10;return r;}
int main()
{
	for(int i=1;i<=15;i++,pw*=10)for(int j=1;j<140;j++)if(j*pw!=1)a[++cc]=j*pw-1;
	sort(a+1,a+cc+1);cc=unique(a+1,a+cc+1)-a-1;
	for(int i=1;i<=cc;i++)if(a[i]<=1e15)
	{
		int ff=1;
		for(int j=i+1;j<=cc;j++)if(a[j]<=1e15)if(a[i]*S(a[j])>a[j]*S(a[i])){ff=0;break;}
		if(ff)b[++tt]=a[i];
	}
	int k;scanf("%d",&k);
	for(int i=1;i<=k;i++)printf("%lld\n",b[i]);
	return 0;
}
