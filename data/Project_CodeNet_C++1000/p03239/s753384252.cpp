#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,t;
	cin>>n>>t;
	
	pair<int,int>p={0,0};
	bool llego=false;
	int a,b;
	
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		if(b<=t)
		{
			if(llego != true)
			{			
				p.first=a;
				p.second=b;
				llego=true;
			}
			else 
			{
				if(p.first>a)
				{
					p.first=a;
					p.second=b;
					llego=true;
				}
			}
		}		
	}
	
	if(p.first==0 && p.second==0)
	{
			cout<<"TLE";
	}
	else
	{
		cout<<p.first;
	}
		
	return  0;	
}