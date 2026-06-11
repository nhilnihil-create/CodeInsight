#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int n;
	cin>>n;
	int shop[n][10];
	ll profit[n][11];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<10;j++)
			cin>>shop[i][j];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<11;j++)
			cin>>profit[i][j];
	}
	int freq[n];ll p=-1000000000000;

	for(int i=0;i<n;i++)
		freq[i]=0;
	for(int i=1;i<1<<10;i++)
	{
		ll tp=0;
		for(int j=0;j<10;j++)
		{
			
			if(i&(1<<j))
			{
				for(int l=0;l<n;l++)
				{
					if(shop[l][j]==1)
						freq[l]++;
				}
			}
			

		}
		for(int k=0;k<n;k++)
		{
			tp += profit[k][freq[k]];
		}
		if(tp>p){
			p=tp;
			//cout<<bitset<5>(i)<<"\n";
		}
		for(int k=0;k<n;k++)
			freq[k]=0;
	}
		
		
		cout<<p<<"\n";
}
