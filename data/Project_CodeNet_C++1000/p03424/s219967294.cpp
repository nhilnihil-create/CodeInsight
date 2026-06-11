#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  string b;
  cin >> a;
  
  for (int i = 0; i < a; i++){
    cin >> b;
    if (b == "Y"){
      cout << "Four" << endl;
      break;
    }
  }
  if (b != "Y")  cout << "Three" << endl;
}


