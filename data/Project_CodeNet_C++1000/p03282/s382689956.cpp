#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  long long K;
  char Y;
  bool M=false;
  cin>>S>>K;
  for(long long X=0;X<K;X++){
    if(S.at(X)!='1'){
      Y=S.at(X);
      M=true;
      break;
    }
  }
  if(M==false){
    cout<<1<<endl;
  }
  else{
    cout<<Y<<endl;
  }
}
