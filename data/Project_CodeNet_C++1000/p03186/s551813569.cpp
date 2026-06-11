#include<cstdio>
#include<iostream>
#define RI register int
#define CI const int&
using namespace std;
int a,b,c;
int main()
{
	return scanf("%d%d%d",&a,&b,&c),printf("%d",b+min(a+b+1,c)),0;
}