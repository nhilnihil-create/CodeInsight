#include<bits/stdc++.h>
using namespace std;
long long arr[1000000];
int main()
{
	string s;
	long long n,i,j,k,m,x,y,z;
	cin>>s;
	x=0;
	y=0;
	i=0;
	while (i<s.length()-1)
	{
		if (s[i]=='A')
		{
			x++;
			i++;
		}
		else if (s[i]=='B' && s[i+1]=='C')
		{
			if (x>0)
			{
				y=x+y;
				x=x;
				i=i+2;
			}
			else
			{
				i=i+2;
			}
		}	
		else
		{
			x=0;
			i++;
		}
	}
	cout<<y<<endl;
}