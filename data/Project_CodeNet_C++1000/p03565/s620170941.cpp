#include <bits/stdc++.h>
using namespace std;

int main(){
  string S,T;
  cin>>S>>T;
  for(int i=S.size()-T.size();i>=0;i--){
    bool bo=false;
    for(int j=0;j<T.size();j++)
      if(T[j]!=S[i+j] && S[i+j]!='?'){
        bo=true;
        break;
      }
    if(bo)
      continue;
    for(int j=0;j<S.size();j++){
      if(j<i || j>i+T.size()-1){
        if(S[j]=='?')
          cout<<'a';
        else
          cout<<S[j];
      }else
        cout<<T[j-i];
    }
    cout<<endl;
    return 0;
  }
  cout<<"UNRESTORABLE"<<endl;
}