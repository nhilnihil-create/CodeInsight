#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

int main() {
  int N;
  cin >> N;
  int n = N;

  int denomi = 0;
  rep(i, to_string(N).length()) {
    if (n < 10) {
      denomi += n;
      break;
    }
    denomi += n % 10;
    n /= 10;
  }

  if (N % denomi == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
