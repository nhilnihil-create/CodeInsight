#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int n,k;
	cin>>n>>k;
	ll v[n];
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	int kk = k;
	ll maxsum=0;
	for(int i=0;i<=min(n,k);i++)
{

	int ab=i;
	for(int j=0;j<=ab;j++)
	{
		int pre=j;
		int suf=ab-j;
		ll sum=0;
		multiset<ll>val;
		for(int l=0;l<pre;l++)
		{
			sum += v[l];
			val.insert(v[l]);
		}
		int count=0;
		for(int l=n-1;l>=0;l--)
		{
			if(count<suf)
			{
				sum += v[l];
				count++;
				val.insert(v[l]);
			}
			else
				break;
		}
		int rem = k-ab;
		while(rem>0&&val.size()>0)
		{
			if(*val.begin()<0){
				sum -= *val.begin();
				val.erase(*val.begin());
				rem--;
			}
			else
				break;

		}
	if(sum>maxsum)
		maxsum=sum;
	}
}
	cout<<maxsum<<"\n";
}