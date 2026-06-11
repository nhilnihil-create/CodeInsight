#include "bits/stdc++.h"
using namespace std;
const int maxN=1e4+10;
int N;
long long a[maxN],b[maxN];
int main()
{
	cin>>N;
	long long sum1=0;
	for(int i=0;i<N;i++)
	{
		cin>>a[i];
		sum1+=a[i];
	}
	long long sum2=0;
	for(int i=0;i<N;i++)
	{
		cin>>b[i];
		sum2+=b[i];
	}
	if(sum1>sum2)
	{
		cout<<"No"<<endl;
		return 0; 
	}
	long long need1=0,need2=0;
	for(int i=0;i<N;i++)
	{
		if(a[i]>b[i])
		{
			need1+=a[i]-b[i];
		}
		else
		{
			need2+=(b[i]-a[i]+1LL)/2LL;
		}
	}
	cout<<(max(need1,need2)<=sum2-sum1?"Yes":"No")<<endl;
	return 0;
}