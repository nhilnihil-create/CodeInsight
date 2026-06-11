#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,b;
	string s;
	cin>>s;
	a=s[0]-48;
	a=a*10+s[1]-48;
	b=s[2]-48;
	b=b*10+s[3]-48;
	if(a<=12&&a>0&&b>0&&b<=12)
	cout<<"AMBIGUOUS";
	else if(a>0&&a<=12)
	cout<<"MMYY";
	else if(b>0&&b<=12)
	cout<<"YYMM";
	else
	cout<<"NA";
	return 0;
}