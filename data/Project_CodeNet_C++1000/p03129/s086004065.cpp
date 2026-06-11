#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, K;
  cin >> N >> K;
  if (N == 1 && K == 1) {
    cout << "YES" << endl;
  } else if (N <= K) {
    cout << "NO" << endl;
  } else {
    if (N % 2 == 0) {
      if (N / 2 >= K) cout << "YES" << endl;
      else cout << "NO" << endl;
    } else {
      if (N / 2 + 1 >= K) cout << "YES" << endl;
      else cout << "NO" << endl;
    }
  }
 
  return 0;
}