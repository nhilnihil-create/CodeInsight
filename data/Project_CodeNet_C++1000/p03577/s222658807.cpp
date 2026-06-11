#include<iostream>
using namespace std;
#include<cstdio>
#include<cstring>
char a[1001];
int main()
{
	scanf("%s",&a);
	int lena=strlen(a);
	for(int i=0;i<lena-8;i++)
	cout<<a[i];
	return 0;
}