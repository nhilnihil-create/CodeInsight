#include <iostream>
#include <vector>
#define MAX_R 100000
using namespace std;
int main(void) {
  int q;
  cin >> q;
  vector<int> l(q), r(q);
  for (int i = 0; i < q; i++) {
    cin >> l[i] >> r[i];
  }
  vector<bool> prime(MAX_R + 1, 1);
  vector<int> count(MAX_R + 1, 0);
  prime[0] = prime[1] = 0;
  for (int i = 2; i * i <= MAX_R; i++) {
    if (prime[i]) {
      for (int j = i * i; j <= MAX_R; j += i) {
        prime[j] = 0;
      }
    }
  }
  for (int i = 3; i <= MAX_R; i++) {
    if (prime[i] && prime[(i + 1) / 2]) {
      count[i] = count[i - 1] + 1;
    } else {
      count[i] = count[i - 1];
    }
  }
  for (int i = 0; i < q; i++) {
    cout << count[r[i]] - count[l[i] - 1] << endl;
  }
  return 0;
}