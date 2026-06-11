#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	cout<<(b/a>c?c:b/a);
	return 0;
}