#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  bool j = true;
  
  for(int i = 0; i < N; i++){
    string S;
    cin >> S;
    if(S == "Y"){
      cout << "Four" << endl;
      j = false;
      break;
    }
  }
  if(j){
    cout << "Three" << endl;
  }
}