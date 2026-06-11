#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int N;
  cin >> N;

  vector<int> C(N-1), S(N-1), F(N-1);
  rep(i, N-1) {
    cin >> C[i] >> S[i] >> F[i];
  }

  rep(i, N-1) {
    long long now = S[i];

    for (int j = i; j < N-1; j++) {
      now = std::max(now, (long long)S[j]);
      for(long long k = now; k <= now * F[j]; k++) {
        if (k % F[j] == 0) {
          now = k;
          break;
        }
      }
      
      now += C[j];
    }

    cout << now << endl;
  }

  cout << 0 << endl;

  return 0;
}
