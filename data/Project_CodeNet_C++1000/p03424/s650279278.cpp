#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string s;
  
  cin >> N;
  
  for(int i; i < N; i++) {
    cin >> s;
    
    if(s == "Y") {
      break;
    }
  }
  
  if(s == "Y")
    cout << "Four" << endl;
  else
    cout << "Three" << endl;
}
