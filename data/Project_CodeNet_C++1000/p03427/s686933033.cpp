#include<bits/stdc++.h>
using namespace std;

int main()
{
  string SN;cin>>SN;
  int sum=0;long long N=0;
  for(int i=SN.size()-1;i>-1;i--)
  {
    N+=(SN[i]-'0')*pow(10,SN.size()-1-i);
    sum+=(SN[i]-'0');
  }
  int ans;
  ans=max((int)(SN[0]-'0'-1+(SN.size()-1)*9),sum);
  cout<<ans;
}