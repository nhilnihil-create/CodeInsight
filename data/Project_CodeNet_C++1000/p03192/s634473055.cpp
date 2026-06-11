#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int a;
int main()
{
	int n=4,s=0;
	while(n--)
	{
		scanf("%1d",&a);
		if(a==2)s++;
	}
	printf("%d\n",s);
	return 0;
}