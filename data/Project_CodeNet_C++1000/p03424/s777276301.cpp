#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N ;
  
  string C;
  bool F = false;
  for(int i = 0; i<N; i++){
    cin >> C;
    if(C == "Y"){
      F = 1;
      break;
    }
  }
  if(F){
    cout << "Four" << endl;
  }
  else{
    cout << "Three" << endl;
  }
}