#include <bits/stdc++.h>
using namespace std;

typedef int64_t Int;

int main(){
  Int N;
  cin>>N;
  bool frag=false;
  for(int h=1;h<=3500;++h){
    for(int n=h;n<=3500;++n){
      Int Q=4*Int(h)*Int(n)-N*(Int(h)+Int(n));
      if(Q>0 && N*Int(n)*Int(h)%Q==0){
        cout<<h<<" "<<n<<" "<<N*Int(n)*Int(h)/Q<<endl;
        frag=true;
        break;
      }
    }
    if(frag){
      break;
    }
  }
}