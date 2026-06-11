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
typedef long long int ll;
 
int main()
{
 int N;
 int ans=10000000;
 scanf("%d",&N);
 for(int i=0;i<N;i++)
 {
	int a;
 	int nw=0;
	scanf("%d",&a);
	for(;;)
	{
		if(a%2==0){nw++; a/=2;}
		else{break;}
	}
	ans=min(ans,nw);
 }
 printf("%d",ans);
} 