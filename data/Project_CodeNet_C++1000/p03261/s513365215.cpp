#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,n,y;
	cin>>n;
	string w[n];
	for(i=0;i<n;i++)
	{
		cin>>w[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(w[i]==w[j])
			{
				cout<<"No"<<endl;
				return 0;
			}
		}
	}
	for(i=1;i<n;i++)
	{
		y=w[i-1].size();
		if(w[i][0]!=w[i-1][y-1])
		{
			cout<<"No"<<endl;
			return 0;
		}
		
	}
	cout<<"Yes"<<endl;
	
}