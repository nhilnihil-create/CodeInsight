#include <bits/stdc++.h>
using namespace std;
long long n,i,j,k,f[100005];
string ans;
long long s(long long x)
{
	long long sum=0;
	while (x)
	{
		sum+=(x%10);
		x/=10;
	}
	return sum;
}
long long len(long long x)
{
	long long sum=0;
	while (x)
	{
		sum++;
		x/=10;
	}
	//if (sum>=12) sum--;
	return sum;
}
int main()
{
	cin>>n;
	int m=0,m2;
	for (i=1;i<=1e15;i*=10)
	{
		f[++m]=i-1;
	}
	m2=m;
	for (i=1;i<=m;i++)
	{
		long long x=1;
		while (x<f[i]) x*=10;
		for (j=1;j<=1000&&j*x+f[i]<=1e15;j++)
		{
			f[++m2]=j*x+f[i];
		}
	}
	sort(f+1,f+m2+1);
	m2=unique(f+1,f+m2+1)-f-1;
	for (i=1;i<=m2;i++)
	{
		for (j=i+1;j<=m2;j++)
		{
			if (f[i]*s(f[j])>f[j]*s(f[i])) f[i]=0;
			if (f[i]==0) break;
		}
	}
	for (i=2;i<=m2;i++) if (f[i]&&(n--)>0) cout<<f[i]<<endl;
	return 0;
}
