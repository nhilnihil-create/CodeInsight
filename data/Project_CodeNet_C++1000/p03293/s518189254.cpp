#include<bits/stdc++.h>
using namespace std;

int main()
{
  string S,T;cin>>S>>T;
  S+=S;
  for(int i=0;i<(int)S.size()-(int)T.size();i++)
  {
    bool check=true;
    for(int j=0;j<(int)T.size();j++)
    {
      if(T[j]!=S[i+j])check=false;
    }
    if(check){printf("Yes\n");return 0;}
  }
  printf("No\n");
}