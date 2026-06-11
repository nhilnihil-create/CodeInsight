#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;
  cin >> N;
  M=0;
  for (int i = 0; i < N; i++) {
    string color;
    cin >> color;
    if (color == "Y"){
      M=1;
      break;
    }
  }
  if (M==0){
    cout << "Three" << endl;
  }else{
    cout << "Four" << endl;
  }
}