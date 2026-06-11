#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;	
	long int x,n;
	cin>>x;
	s=to_string(x);


	
	n=s.size();
	int i,d=0,y=s[0]-'0';
	y=y+((n-1)*9);
	y--;
	if(x<10)
	{
		cout<<x<<endl;
		return 0;
	}		
	for(i=0;i<n;i++)
	{
		
		if(s[i]=='9')
		{
			d++;
		}
	
		if(d==n-1 && s[0]!='9')
		{
			
			y++;
		}
		if(d==n)
		{
			cout<<n*9<<endl;
			return 0;
		}
	}
		cout<<y<<endl;
	
	
}