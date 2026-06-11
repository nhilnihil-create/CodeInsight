#include <bits/stdc++.h>
using namespace std;

int main(){
  int i, N;
  bool flag = false;
  cin >> N;
  string s[N];
  for(i = 0; i < N; i++){
    cin >> s[i];
    if(s[i] == "Y"){
      flag = true;
      continue;
    }
  }
  if(flag){
    cout << "Four" << endl;
  }else{
    cout << "Three" << endl;
  }

  return 0;
}