#include <bits/stdc++.h>
using namespace std;

int main(){
  string S,T;
  cin>>S>>T;
  int N=S.size();
  for(int i=0;i<N;i++){
    bool bo=false;
    for(int j=0;j<N;j++){
      if(S[(j+i)%N]!=T[j]){
        bo=true;
        break;
      }
    }
    if(bo)
      continue;
    cout<<"Yes"<<endl;
    return 0;
  }
  cout<<"No"<<endl;
}