#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  bool isFour = false;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    if (s == "Y") {
      isFour = true;
      cout << "Four" << endl;
      break;
    }
  }
  if (!isFour)
    cout << "Three" << endl;
}

