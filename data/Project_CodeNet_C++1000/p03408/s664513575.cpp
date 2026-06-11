#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N,M;scanf("%d",&N);
  string s[N];for(int i=0;i<N;i++)cin>>s[i];
  scanf("%d",&M);
  string t[M];
  for(int i=0;i<M;i++)cin>>t[i];
  map<string,int> m;
  for(int i=0;i<N;i++)m[s[i]]++;
  for(int i=0;i<M;i++)m[t[i]]--;
  int ans=0;
  for(auto ite : m)ans=max(m[ite.first],ans);
  printf("%d",ans);
}