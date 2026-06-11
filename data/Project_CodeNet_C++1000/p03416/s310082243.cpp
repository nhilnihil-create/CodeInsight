#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int ttl = 0;
  rep2(i, A, B + 1) {
    if ((i % 10 == i / 10000 % 10) && (i / 10 % 10 == i / 1000 % 10)) {
      ttl += 1;
    }
  }
  cout << ttl << endl;
}
