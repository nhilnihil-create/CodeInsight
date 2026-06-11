#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  bool L=false;
  long long K;
  cin>>S>>K;
  for(int X=0;X<K;X++){
    if(S.at(X)!='1'){
      cout<<S.at(X);
      L=true;
      break;
    }
  }
  if(L==false){
    cout<<1<<endl;
  }
}
