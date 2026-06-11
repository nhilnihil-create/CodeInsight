#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  int N;
  cin >> N;
  string co;
  int C = 0;
  rep(i, N) {
    cin >> co;
    if(co == "Y") {
      C += 0;
    }
    else {
      C++;
    }
  }
  if(C == N) {
    cout << "Three" << endl;
  }
  else {
    cout << "Four" << endl;
  }
}
