#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
char a[11001],c;
int main()
{
	cin>>a;
	int t=strlen(a);
	for(int i=0;i<t;i++)
	{
		if(a[i]=='x')c++;
		}
	if(c>=8)printf("NO");
	else printf("YES");	
	return 0;
}