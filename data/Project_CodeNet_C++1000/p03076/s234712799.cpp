#include<bits/stdc++.h>
using namespace std;

int main()
{
  int food[5];for(int i=0;i<5;i++)scanf("%d ",&food[i]);
  int ans=0;int last=0;
  for(int i=0;i<5;i++)
  {
    if(food[i]%10!=0)
    {
      last=max(10-food[i]%10,last);
      ans+=((food[i]/10)+1)*10;
    }else ans+=food[i];
  }
  ans-=last;
  printf("%d",ans);
}