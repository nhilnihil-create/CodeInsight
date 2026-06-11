#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N,M;scanf("%d %d",&N,&M);
  vector<int> foods(M+1,0);
  for(int K,i=0;i<N;i++)
  {
    cin>>K;vector<int> A(K);vector<bool> check(M+1,false);
    for(int i=0;i<K;i++)
    {
      cin>>A[i];check[A[i]]=true;
    }
    for(int i=0;i<M+1;i++)if(check[i])foods[i]++;
  }
  int ans=0;
  for(int i=0;i<M+1;i++)if(foods[i]==N)ans++;
  printf("%d\n",ans);
}