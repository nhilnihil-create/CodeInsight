#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int curx=0,cury=0,curt=0;
	for(int i=0;i<n;i++)
	{
		int t,x,y;
		cin>>t>>x>>y;
		int tm=t-curt;
		int dis=abs(curx-x)+abs(cury-y);
		if(dis<=tm)
		{
			int extra=tm-dis;
			if(extra&1)
			{
				cout<<"No";
				return 0;
			}
		}
		else
		{
			cout<<"No";
			return 0;
		}
		curx=x;
		cury=y;
		curt=t;
	}
	cout<<"Yes";
	return 0;
}
