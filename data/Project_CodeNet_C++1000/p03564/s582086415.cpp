#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, result=1, ans=1025;
  cin >> N >> K;
  
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j < i; j++) result = result * 2;
    for (int a = 0; a < N-i; a++) result = result + K;
    if (result < ans) ans = result;
    result = 1;
  }

  cout << ans << endl;
}