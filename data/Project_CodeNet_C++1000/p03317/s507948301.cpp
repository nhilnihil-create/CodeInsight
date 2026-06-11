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
 int N,K;
 int loc1;
 scanf("%d %d",&N,&K);
 for(int i=1;i<=N;i++)
 {
	int a; scanf("%d",&a);
	if(a==1){loc1=i;}
 }
 int z=K-1;
 int ans=(N-1)/z;
 if((N-1)%z!=0){ans++;}
 printf("%d",ans);
} 