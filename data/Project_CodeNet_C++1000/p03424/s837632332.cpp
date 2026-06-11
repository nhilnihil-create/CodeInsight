#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string Si;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> Si;
    
    if (Si == "Y"){
      cout << "Four" << endl;
      break;
    }
  }
  
  if (Si == "P" || Si == "W" || Si == "G"){
    cout << "Three" << endl;
  }
  

}