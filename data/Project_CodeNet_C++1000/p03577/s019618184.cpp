#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char s[55]; 
int main()
{
	cin>>s;
	for(int i=0;i<strlen(s)-8;i++)
	cout<<s[i];
	cout<<endl;
	return 0;
}