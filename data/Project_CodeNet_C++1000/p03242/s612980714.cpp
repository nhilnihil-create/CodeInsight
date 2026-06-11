#include<iostream>
#include<cstring>
using namespace std;
char s[10000000];
int main()
{
	cin>>s;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]=='1')
		s[i]='9';
		else if(s[i]=='9')
		s[i]='1';
	}
	cout<<s<<endl;
 } 