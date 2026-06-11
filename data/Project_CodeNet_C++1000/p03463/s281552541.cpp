#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
long long n,x,y,s;
using namespace std;
int main()
{
	cin>>n>>x>>y;
	while(1)
	{
		if(x+1==y)
		{
			if(s%2==1) cout<<"Alice";
			else cout<<"Borys";
			return 0;
		}
		if(!s%2) x++;
		else y--;
		s++;
	}
	return 0;
}