#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int i;
  string text;
  bool flag=false;
  cin>>i;

  while(i>0){
    cin>>text;
    if(text=="Y"){
      flag=true;
      break;
    }
    i--;
  }

  if(flag) cout<<"Four"<<endl;
  else cout<<"Three"<<endl;
}