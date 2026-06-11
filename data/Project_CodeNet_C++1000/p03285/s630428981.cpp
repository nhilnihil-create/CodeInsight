#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  bool ans=false;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(N==4*i+7*j){
        ans=true;
      }
    }
  }
  
  if(ans){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}