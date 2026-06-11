#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  bool bo=false;
  for(int i=0;i<S.size();i++){
    if(i==0){
      if(S[i]!='A'){
        cout<<"WA"<<endl;
        return 0;
      }
    }else if('A'<=S[i] && S[i]<='Z'){
      if(i==1 || i==S.size()-1 || S[i]!='C' || bo){
        cout<<"WA"<<endl;
        return 0;
      }else
        bo=true;
    }
  }
  if(bo)
    cout<<"AC"<<endl;
  else
    cout<<"WA"<<endl;
}