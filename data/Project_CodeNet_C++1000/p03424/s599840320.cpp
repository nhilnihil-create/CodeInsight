#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, a;
  string b;
  cin >> N;
  a = 0;
  
  for (int i = 0; i < N; i++) {
    cin >> b;
    if (b == "Y") {
      a = 1;
    }
  }
  
  if (a == 0){
    cout << "Three" << endl;
  }
  else if (a == 1){
    cout << "Four" << endl;
  }
}