#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int n,m,i;
	scanf("%d",&n);
	for(i=1;i<=9;i++)
	{
		m=i*100+i*10+i;
		if(m>=n) {printf("%d",m);break;}
	}
}
