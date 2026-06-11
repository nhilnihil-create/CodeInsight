#include<bits/stdc++.h>
using namespace std;

int main()
{
  string S;long long K;cin>>S;scanf("%lld",&K);
  long long count1=0;int ans=1;
  for(int i=0;i<S.size();i++)
  {
    if(count1==K){break;}
    if(S[i]=='1'){count1++;continue;}
    ans=S[i]-'0';break;
  }
  cout<<ans;
}