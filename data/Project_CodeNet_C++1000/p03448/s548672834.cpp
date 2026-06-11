#include<bits/stdc++.h>
using namespace std;

int main()
{
int A,B,C,X;scanf("%d\n%d\n%d\n%d",&A,&B,&C,&X);
int count=0;
for(int a=0;a<A+1;a++)for(int b=0;b<B+1;b++)if(X-a*500-b*100>=0&&C*50>=X-a*500-b*100)count++;
printf("%d\n",count);
}