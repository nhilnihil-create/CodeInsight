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
 int N,T;
 scanf("%d %d",&N,&T);
 int ans=1000000;
 for(int i=0;i<N;i++)
 {
	int c,t;
	scanf("%d %d",&c,&t);
	if(t<=T){ans=min(ans,c);}
}
 if(ans==1000000){printf("TLE");}
 else{printf("%d",ans);}
} 