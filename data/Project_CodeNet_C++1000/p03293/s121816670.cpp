#include <bits/stdc++.h>
using namespace std;
int main()
{
	string k,s,t;
	cin>>s>>t;
	int n;
	n=s.size();
	int x=n,i,j;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(s.substr(i)+s.substr(0,i)==t)
			{
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	}
	cout<<"No"<<endl;
}