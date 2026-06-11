#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i,a,b,x=0,c[10];
	string s;
	cin>>s;
	a=s.size();
	for(i=0;i<a;i++)
	{
		if(s[i]=='A' || s[i]=='C' || s[i]=='G' || s[i]=='T')
		{
			x++;
		}
		else
		{
			x=0;
		}
		c[i]=x;
	}
	sort(c,c+a);
	cout<<c[a-1]<<endl;
}