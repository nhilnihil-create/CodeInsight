#include <bits/stdc++.h>
using namespace std;
 

int main() {
  int N;
  cin>>N;
  
  bool ike =false;
  for(int i=0;i<40;i++){
    for(int j=0;j<20;j++){
      if(4*i+7*j==N){
        ike=true;
        break;
      }
    }
  }
  if(ike) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
      