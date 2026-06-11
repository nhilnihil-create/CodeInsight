#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> W(N);
  bool ok = true;
  for (int i = 0; i < N; i++) {
    cin >> W.at(i);
    for (int j = 0; j < i; j++) {
      if (W.at(i) == W.at(j)) {
        ok = false;
      }
    }
  } 
  for (int i = 1; i < N; i++) {
    int C = (W.at(i - 1)).size(); 
    if ((W.at(i - 1)).at(C - 1) != (W.at(i)).at(0)) {
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}