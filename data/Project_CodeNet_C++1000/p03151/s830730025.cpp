#include <bits/stdc++.h>
#define SIZE 100005
using namespace std;
typedef long long int ll;
ll A[SIZE],B[SIZE];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",&A[i]);
	for(int i=0;i<n;i++) scanf("%lld",&B[i]);
	ll sa=0,sb=0;
	for(int i=0;i<n;i++) sa+=A[i],sb+=B[i];
	if(sa<sb)
	{
		puts("-1");
		return 0;
	}
	int cnt=0;
	ll d=0;
	vector <ll> vx;
	for(int i=0;i<n;i++)
	{
		if(A[i]<B[i])
		{
			d+=B[i]-A[i];
			cnt++;
		}
		else
		{
			vx.push_back(A[i]-B[i]);
		}
	}
	sort(vx.begin(),vx.end(),greater <ll>());
	for(int i=0;i<vx.size();i++)
	{
		if(d>0)
		{
			d-=vx[i];
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}