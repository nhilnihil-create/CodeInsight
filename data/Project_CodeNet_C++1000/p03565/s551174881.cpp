#include<bits/stdc++.h>
using namespace std;

int main()
{
  vector<string> S;
  string Sdot,Schanged,T;cin>>Sdot>>T;bool check=true;
  for(int i=Sdot.size()-T.size();i>-1;i--)
  {
    check=true;
    for(int j=0;j<T.size();j++)
    {
      if(Sdot[i+j]!=T[j]&&Sdot[i+j]!='?'){check=false;break;}
    }
    Schanged=Sdot;
    if(check)
    {
      for(int j=0;j<T.size();j++)Schanged[i+j]=T[j];
      for(int i=Sdot.size();i>-1;i--)if(Schanged[i]=='?')Schanged[i]='a';
      S.push_back(Schanged);
    }
  }
  if(S.size()==0){printf("UNRESTORABLE\n");return 0;}
  else sort(S.begin(),S.end());
  cout<<S[0]<<endl;
}