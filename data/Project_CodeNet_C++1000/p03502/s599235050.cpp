#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, t, c;
  cin >> N;
  t = N; c = 0;
  while(t > 0) {
    c += t % 10;
    t /= 10;
  }
  if(N % c == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}