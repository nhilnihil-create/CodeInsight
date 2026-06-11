#include<bits/stdc++.h>
using namespace std;

int main()
{
  int A,B,K;scanf("%d %d %d",&A,&B,&K);
  set<int> s;
  for(int i=A;i<A+K;i++){if(i>B)continue;printf("%d\n",i);s.insert(i);}
  for(int i=B-K+1;i<B+1;i++){if(i<A)continue;if(!s.count(i))printf("%d\n",i);}
}