#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int K;
	scanf("%d",&K);
	if(K%2==0)printf("%d",K*K/4);
	else printf("%d", (K/2) *(K+1)/2);
}
