#include<bits/stdc++.h>
using namespace std;
stack<int> oo;
string u;
int ans=0,j=1;
int b[100010];
int main()
{
	cin>>u;
	for(int i=0;i<u.size();i++)
	{
		b[i]=u[i]-'0';
	}
//	cout<<u.size();
	
	for(int i=0;i<u.size();i++)
	{
		if(oo.empty())
		{
			oo.push(b[i]);
			continue;
		}
		if(b[i]!=oo.top())
		{
			ans+=2;
			oo.pop();
			continue;
		}
		 if(b[i]==oo.top())
		{
			oo.push(b[i]);
			continue;
		}
	}
	cout<<ans;
	return 0;
} 