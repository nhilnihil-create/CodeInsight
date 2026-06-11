#include<bits/stdc++.h>
#include<map>
#include<vector> 
using namespace std;
typedef long long LL;
const int maxn=1<<19;
typedef pair< int , int > PII;
PII a[maxn]; int b[maxn]; 

PII work(int i,int j)
{
	int fmax=a[i].first;
	int smax=a[i].second;
	if(a[j].first>fmax)
	{
		smax=fmax;
		fmax=a[j].first;
	}
	else if(a[j].first>smax) smax=a[j].first;
	else if(a[j].second>smax) smax=a[j].second;
	return make_pair(fmax,smax);
}


int main(void)
{
	int n; scanf("%d",&n);
	int len=1<<n;
	for(int i=0;i<len;i++) scanf("%d",&b[i]);
	for(int i=0;i<len;i++) a[i]=make_pair(b[i],-1);
	for(int i=0;i<n;i++)
	{
		for(int s=0;s<len;s++)
		{
			if((s>>i)&1) a[s]=work(s,(s^(1<<i)));
		}
	}
	int res=-1;
	for(int i=1;i<len;i++)
	{
		res=max(res,a[i].first+a[i].second);
		printf("%d\n",res);
	}
	return 0;
}