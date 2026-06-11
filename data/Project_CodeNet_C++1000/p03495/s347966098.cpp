#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, K, A, i, j, ans = 0;
  cin >> N >> K;
  vector<int> num(N);
  for (i = 0; i < N; i++) {
    cin >> A;
    num.at(A - 1)++;
  }
 
  sort(num.begin(), num.end());
  reverse(num.begin(), num.end());
  
  for (i = K; i < N; i++) ans += num.at(i);
  cout << ans << endl;
}
