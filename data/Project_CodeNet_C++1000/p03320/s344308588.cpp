#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
vector<long long>ans;
long long snum(long long x)
{
	long long s=0;
	while (x) s+=x%10,x/=10;
	return s;
}
double f(long long x)
{
	return (double)x/(double)snum(x);
}
bool check(long long x)
{
	if (x<10000 || x>10000000000ll) return false;
	while (x%10==0) x/=10;
	if (x==1) return true;
	return false; 
}
int main()
{
	vector<long long> ans;
	long long stp=1;
	for (long long i=1;i<=1e15;i+=stp)
	{
		long long tm=1;
		if (check(i+1ll)) stp=(i+1ll)/10;
		long long tmp=i;
		while (tmp%10==9) tmp/=10,tm*=10;
		if (f(i)<=f(i+tm)) ans.push_back(i);
	}
	int k;
	scanf("%d",&k);
	for (int i=0;i<k;i++)
		printf("%lld\n",ans[i]);
	return 0;
}
