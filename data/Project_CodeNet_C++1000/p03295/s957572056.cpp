#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N,M;scanf("%d %d",&N,&M);
  pair<int,int> endstart[M];
  for(int a,b,i=0;i<M;i++)
  {
    scanf("%d %d",&a,&b);
    if(a>b)swap(a,b);
    endstart[i].first=b;endstart[i].second=a;
  }
  sort(endstart,endstart+M);
  int ans=1,t=endstart[0].first;
  for(int i=1;i<M;i++)if(t<=endstart[i].second){ans++;t=endstart[i].first;}
  printf("%d\n",ans);
}