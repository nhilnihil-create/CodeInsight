#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  bool four=false;
  for (int i=0; i < n; i++) {
    cin >> s;
    if (s=="Y")
      four=true;
  }
  if (four)
    cout << "Four";
  else
    cout << "Three";
}

