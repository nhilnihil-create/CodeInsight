#include<bits/stdc++.h>
using namespace std;

int main()
{
  string S;cin>>S;string ans="NO";
  for(int f=0;f<S.size();f++)for(int m=0;m<S.size();m++)
  {
    if(f+m>S.size())continue;
    int l=S.size()-f-m;
    string check;
    for(int i=0;i<f;i++)check+=S[i];
    for(int i=f+m;i<S.size();i++)check+=S[i];
    if(check=="keyence")ans="YES";
  }
  cout<<ans<<endl;
}