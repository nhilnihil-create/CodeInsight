#include<bits/stdc++.h>
using namespace std;

int sum(int num)
{
  string s=to_string(num);int su=0;
  for(int i=0;i<s.size();i++)su+=s[i]-'0';
  return su;
}

int main()
{
  int ans=0,N,A,B;scanf("%d %d %d",&N,&A,&B);
  for(int n,i=1;i<N+1;i++)
  {
    n=sum(i);
    if(n>=A&&n<=B)ans+=i;
  }
  printf("%d\n",ans);
}