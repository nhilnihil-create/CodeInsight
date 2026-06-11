#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
  long long K, A, B;
  cin >> K >> A >> B;

  if (A + 2 >= B || K < A - 1) {
    cout << K + 1 << endl;
    return 0;
  } else {
    long long tot = A;
    long long cnt = K - A + 1;
    if ((K - A) % 2 == 0) tot++, cnt--;
    tot += (B - A) * (cnt / 2);
    cout << tot << endl;
  }
}