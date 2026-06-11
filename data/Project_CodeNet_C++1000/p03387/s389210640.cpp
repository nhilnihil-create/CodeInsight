#include<bits/stdc++.h>
using namespace std;

int main()
{
  int num[3];scanf("%d %d %d",&num[0],&num[1],&num[2]);
  sort(num,num+3);
  int ans=num[2]-num[1];
  num[0]=num[0]+num[2]-num[1];
  num[1]=num[2];
  if((num[2]-num[0])%2==0)ans+=((num[2]-num[0])/2);
  else ans+=((num[2]-num[0]+1)/2+1);
  printf("%d",ans);
}