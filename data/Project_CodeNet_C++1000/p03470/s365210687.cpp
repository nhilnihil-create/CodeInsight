#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;scanf("%d",&N);
  int d[N];
  for(int i=0;i<N;i++)scanf("%d",&d[i]);
  set<int> s;int ans=0;
  for(int i=0;i<N;i++)if(!s.count(d[i])){ans++;s.insert(d[i]);}
  printf("%d\n",ans);
}