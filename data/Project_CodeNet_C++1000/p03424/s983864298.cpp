#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  string S;
  bool flag = false;
  for(int i = 0; i < N; i++){
    cin >> S;
    if(S == "Y"){
      flag = true;
    }
  }
  if(flag){
    cout << "Four" << endl;
  }
  else{
    cout << "Three" << endl;
  }
}  
