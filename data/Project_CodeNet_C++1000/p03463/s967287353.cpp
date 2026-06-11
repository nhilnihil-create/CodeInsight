#include<iostream>
#include<cstdio>
#define c b-a
using namespace std;
int n,a,b;
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	if(c&1) printf("Borys");
	else printf("Alice");
	printf("\n");
	return 0;
}