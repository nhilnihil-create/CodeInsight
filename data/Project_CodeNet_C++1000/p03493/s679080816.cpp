#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N,ans;
  cin >> N;
  ans = N / 100 + N / 10 % 10 + N % 10;
  cout << ans << endl;
}
