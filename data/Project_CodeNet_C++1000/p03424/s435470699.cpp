#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  vector<char> S(N);
  bool ans = false;
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> S.at(i);
  }
  for(int i = 0; i < N; i++) {
    if(S.at(i) == 'Y') {
      ans = true;
      break;
    }
  }
  if(ans) {
    cout << "Four" << endl;
  } else {
    cout << "Three" << endl;
  }

  return 0;
}