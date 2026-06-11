#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int N;
  cin >> N;
  if(N < 105) {
    cout << 0 << endl;
  }
  else if(N < 135) {
    cout << 1 << endl;
  }
  else if(N < 165) {
    cout << 2 << endl;
  }
  else if(N < 189) {
    cout << 3 << endl;
  }
  else if(N < 195) {
    cout << 4 << endl;
  }
  else if(N <= 200) {
    cout << 5 << endl;
  }
}
