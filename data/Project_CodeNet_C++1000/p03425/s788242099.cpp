#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int n;
	cin>>n;
	string s[n];
	for(int i=0;i<n;i++)
		cin>>s[i];
	ll m=0,a=0,r=0,c=0,h=0;
	for(int i=0;i<n;i++)
	{
		if(s[i][0]=='M')
			m++;
		else if(s[i][0]=='A')
			a++;
		else if(s[i][0] =='R')
			r++;
		else if(s[i][0]=='C')
			c++;
		else if(s[i][0]=='H')
			h++;

	}

	ll ways = m*a*r + m*a*c + m*a*h + m*r*c + m*r*h + m*c*h + a*r*c + a*r*h + a*c*h + r*c*h;
	cout<<ways<<"\n";
}
