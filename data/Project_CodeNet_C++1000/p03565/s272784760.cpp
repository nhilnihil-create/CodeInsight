#include <bits/stdc++.h>
using namespace std;
int main(){
  string S,T;cin>>S>>T;
  vector<string>A;
  for(int i=0;i<S.size()-T.size()+1;i++){
    string s=S;
    bool b=false;
    for(int j=i;j<i+T.size();j++){
      if(S.at(j)=='?'){s.at(j)=T.at(j-i);continue;}
      if(S.at(j)!=T.at(j-i)){b=true;break;}
      }
    if(!b){
      for(int k=0;k<S.size();k++)if(s.at(k)=='?')s.at(k)='a';
      A.push_back(s);
    }
  }
  if(A.size()==0)puts("UNRESTORABLE");
  else{
    sort(A.begin(),A.end());
    cout<<A[0]<<endl;
  }
}