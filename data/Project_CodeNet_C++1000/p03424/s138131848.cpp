#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string a;
  for (int i = 0; i < N; i++) {
    cin >> a;
    if(a == "Y"){
      cout << "Four" << endl;
      exit(0);
    }
  }
  cout << "Three" << endl;
  
}