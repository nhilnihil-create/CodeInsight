#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>key[m];
	for(int i=0;i<m;i++)
	{
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int x;
			cin>>x;
			key[i].push_back(x);
		}
	}
	int p[m];
	for(int i=0;i<m;i++)
		cin>>p[i];
	int arr[n];
	int res=0;
	for(int i=0;i<1<<n;i++)
	{
		for(int j=0;j<n;j++)
		{
				if(i&(1<<j))
					arr[j]=1;
				else
					arr[j]=0;
		}
		int count=0;
		for(int l=0;l<m;l++)
		{
			int tab=0;
			for(auto x : key[l])
			{
				if(arr[x-1]==1)
					tab++;
			}
			if(tab%2==p[l]%2)
				count++;
		}
		if(count==m)
			res++;

	}
	cout<<res<<"\n";
}