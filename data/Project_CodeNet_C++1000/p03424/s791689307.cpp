#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  for(; N > 0; N--) {
    string s;
    cin >> s;
    if(s == "Y") break;
  }
  if(N) cout << "Four" << endl;
  else cout << "Three" << endl;
}