#include<bits/stdc++.h>
using namespace std;

int main()
{
  string S;cin>>S;
  long long B=0,W=0,ans=0;
  for(int i=0;i<S.size();i++)if(S[i]=='W'){ans+=(i-W);W++;}
  printf("%lld",ans);
}