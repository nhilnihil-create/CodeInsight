#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> a(5);
  
  for(int i = 0; i < 5; i++){
    cin >> a.at(i);
  }
  
  int k;
  cin >> k;
  
  bool ans = true;
  int bre = 0;
  
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      if(max(a.at(i),a.at(j))-min(a.at(i),a.at(j))>k){
        ans = false;
        bre = 1;
      }
    }
    if(bre==1){
      break;
    }
  }
  
  if(ans){
    cout << "Yay!" << endl;
  }
  else{
    cout << ":(" << endl;
  }
  
}