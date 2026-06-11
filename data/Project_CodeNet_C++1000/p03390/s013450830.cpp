#include <bits/stdc++.h>
using namespace std;

int Q;

int main() {
  cin >> Q;
  for(int q = 0; q < Q; ++q) {
    long long A, B; cin >> A >> B;
    if(A > B) swap(A, B);
    if(A == B) cout << 2 * (A - 1) << endl;
    else if(A + 1 == B) cout << 2 * (A - 1) << endl;
    else {
      long long C = floorl(sqrtl(1.0L * (A * B - 1)));
      if(C * (C + 1) >= A * B) cout << (A - 1) + (C + C - (A + 1)) << endl;
      else cout << (A - 1) + (C + (C + 1) - (A + 1)) << endl;
    }
  }
  return 0;
}
