#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	int mx=max(a,max(b,c));
	if((mx*3-(a+b+c))%2==0)
		printf("%d\n",(mx*3-(a+b+c))>>1);
	else
		printf("%d\n",(mx*3-(a+b+c)+3)>>1);
}