#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<locale.h>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;

int main()
{
 long long int x,y;
 scanf("%lld %lld",&x,&y);
 y/=x;
 int ans=0;
 for(;;)
 {
	ans++;
	y/=2;
//	printf("%d %d\n",ans,y);
	if(y==0){break;}
 }
 printf("%d",ans);
}

