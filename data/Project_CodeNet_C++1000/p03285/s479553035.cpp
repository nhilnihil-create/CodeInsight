#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  bool ok=false;
   for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
      if((N-4*i-7*j)==0) ok=true;
    }
  }
  if(ok==false) cout<<"No"<<endl;
  else cout <<"Yes"<<endl;

return 0;
}
