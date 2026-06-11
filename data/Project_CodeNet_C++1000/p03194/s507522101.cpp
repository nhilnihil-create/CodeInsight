#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
long long nn,mm;
long long ans=1;

using namespace std;
long long a[1000001][2];
long long tot;
inline void prim()
{
	long long sq=sqrt(mm)+1,cnt;
	for(long long i=2;i<=sq;i++)
	if(mm%i==0)
	{
		tot++;
		cnt=0;
		a[tot][1]=i;
		while(mm%i==0)
		{
			cnt++;
			mm/=i;
		}
		a[tot][0]=cnt;
	}
}
long long kuai(long long kk,long long pp)
{
	long long anss=1,tmp=kk;
	for(long long i=pp;i;i>>=1)
	{
		if(i&1ll)
		{
			anss=anss*tmp;
		}
		tmp=tmp*tmp;
	}
	return anss;
}
/*
void did(long long mm)
{
	for(long long i=1;i<=1000001;i++)
	{
		long long bs=0;
		while(mm%prim[i]==0)
		{
			mm=mm/prim[i];
			bs++; 
		}
		long long ph=bs/nn;
		ans=ans*kuai(prim[i],ph);
		if(mm==1||prim[i+1]==0)
		{
			break;
		}
	}
}
*/
signed main()
{
	cin>>nn>>mm;
//	prime();
//	did(mm);
	if(nn==1)
	{
		cout<<mm<<endl;
		return 0;
	}
	a[++tot][1]=1;a[tot][0]=nn;
	prim();
	for(long long i=tot;i>=1;i--)
	if(a[i][0]>=nn)
	{
		long long tmp=a[i][0]/nn;
		ans*=kuai(a[i][1],tmp);
	}
	cout<<ans<<endl;
	return 0;
}