#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
string s;
int read()
{
	char chr;
	int f=1;
	while (((chr=getchar())<'0')||(chr>'9'))
	{
		if (chr=='-')
		{
			f=-1;
		}
	}
	int res=chr-'0';
	while (((chr=getchar())>='0')&&(chr<='9'))
	{
		res=res*10+chr-'0';
	}
	return res*f;
}
int main()
{
	cin>>s;
	s.erase(s.length()-8,s.length()-1);
	cout<<s<<"\n";
	return 0;
}