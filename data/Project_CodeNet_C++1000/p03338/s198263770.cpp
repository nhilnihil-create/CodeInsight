#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;scanf("%d",&N);
  char S[N];
  for(int i=0;i<N;i++)cin>>S[i];
  int XY[26];fill(XY,XY+26,0);
  bool counted[26];fill(counted,counted+26,false);
  for(int i=0;i<N;i++)XY[S[i]-'a']++;
  int ans=0,current=0;
  for(int i=0;i<N;i++)
  {
    int num=S[i]-'a';
    if(XY[num]>=2&&!counted[num])ans=max(ans,current++),counted[num]=true;
    if(XY[num]==1&&counted[num])ans=max(ans,current--);
    XY[num]--;
  }
  printf("%d",ans);
}