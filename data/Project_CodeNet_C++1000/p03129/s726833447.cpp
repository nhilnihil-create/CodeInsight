#include <bits/stdc++.h>
using namespace std;
int main () {
  int N, K;
  cin >> N >> K;
  long count = 0;
  count = (N + 1) / 2;
  if(count >= K)cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
