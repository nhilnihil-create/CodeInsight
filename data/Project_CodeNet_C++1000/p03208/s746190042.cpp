#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N,K;scanf("%d %d",&N,&K);
  int h[N];
  for(int i=0;i<N;i++)scanf("%d\n",&h[i]);
  sort(h,h+N);int ans=1000000000;
  for(int i=0;i<N-K+1;i++)ans=min(ans,h[i+K-1]-h[i]);
  cout<<ans;
}