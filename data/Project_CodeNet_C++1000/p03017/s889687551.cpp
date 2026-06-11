#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n,a,b,c,d;
	string s;
	cin >> n >> a >> b >> c >> d;
	cin >> s;
	a--;
	b--;
	c--;
	d--;
	for(int i = a;i<c;i++)
	{
		if(s[i]=='#'&&s[i+1]=='#')
		{
			cout<<"No"<<endl;
			return 0;
		}
	}
	for(int j = b;j<d;j++)
	{
		if(s[j]=='#'&&s[j+1]=='#')
		{
			cout<<"No"<<endl;
			return 0;
		}
	}
	if(d<c)
	{
		bool is = true;
		for(int i = b;i<=d;i++)
		{

			if(s[i-1]=='.'&&s[i]=='.'&&s[i+1]=='.')
			{
				is = false;
			}
		}
		if(is)
		{
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}
