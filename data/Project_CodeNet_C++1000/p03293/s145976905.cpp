#include <bits/stdc++.h>
using namespace std;

int main(){
  string S,T;
  cin>>S>>T;
  int N=S.size();
  bool flag=true;
  int i=0;
  while(S!=T){
    S.push_back(S[0]);
    S.erase(S.begin(),S.begin()+1);
    if (i==3*N){
      flag=false;
      break;
    }
    i++;
  }
  if (flag){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}
  