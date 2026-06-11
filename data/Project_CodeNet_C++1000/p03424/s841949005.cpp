#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  rep(i, N) {
    string S;
    cin >> S;
    if (S=="Y") {
      cout << "Four" << endl;
      return 0;
    }
  }
  cout << "Three" << endl;
}
