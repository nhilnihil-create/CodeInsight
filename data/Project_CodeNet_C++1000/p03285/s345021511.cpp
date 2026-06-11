#include<bits/stdc++.h>
using namespace std;
int main(){
  int a;
  cin >> a;
  bool ok=false;
  for(int i=0;i<26;i++){
    for(int j=0;j<15;j++){
      if(a==i*4+j*7){
        cout << "Yes" << endl;
        ok=true;
        break;
      }
    }
    if(ok)break;
  }
  if(ok==false)cout << "No" << endl;
}
