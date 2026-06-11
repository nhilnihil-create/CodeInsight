#include <iostream>
#include <algorithm>
using namespace std;

const int N_MAX=1000;
typedef long long int LLI;

int main() {
  int N;
  LLI x[N_MAX];
  LLI y[N_MAX];

  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> x[i] >> y[i];
  }

  bool impossible = false;
  bool odd;
  for (int i = 0; i < N; ++i) {
    if (!i) {
      odd = abs(x[i] + y[i]) % 2;
    } else if (odd != abs(x[i] + y[i]) % 2) {
      impossible = true;
    }
  }

  if (impossible) {
    cout << -1 << endl;
    return 0;
  }

  LLI k = 0;
  for (int i = 0; i < N; ++i) {
    if (!odd) {
      --x[i];
    }
    k = max(k, abs(x[i] + y[i]));
    k = max(k, abs(x[i] - y[i]));
  }
  int m = 0;
  LLI mm = 1;
  while (mm <= k) {
    m += 1;
    mm <<= 1;
  }

  if (!odd) {
    cout << m + 1 << endl;
    cout << 1 << " ";
  } else {
    cout << m << endl;
  }
  LLI p = 1;
  for (int i = 0; i < m; ++i) {
    if (!i) {
      cout << p;
    } else {
      cout << " " << p;
    }
    p <<= 1;
  }
  cout << endl;

  for (int i = 0; i < N; ++i) {
    if (!odd) {
      cout << "R";
    }
    LLI u = x[i] + y[i];
    LLI v = x[i] - y[i];
    LLI a = ((1 << m) - 1 - u) / 2;
    LLI b = ((1 << m) - 1 - v) / 2;

    for (int i = 0; i < m; ++i) {
      char d;
      if (a & 1) {
        if (b & 1) {
          d = 'L';
        } else {
          d = 'D';
        }
      } else {
        if (b & 1) {
          d = 'U';
        } else {
          d = 'R';
        }
      }
      a >>= 1;
      b >>= 1;
      cout << d;
    }
    cout << endl;
  }
  return 0;
}
