#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;
using Graph = vector<vector<int>>;

bool isEightDivisor(int num) {
  int divisor = 0;
  for (int i = 1; i <= num; i++) {
    if (num % i == 0) divisor++;
  }

  return divisor == 8;
}

int main() {
  int N;
  cin >> N;
  int ans = 0;

  for (int i = 1; i <= N; i += 2) {
    if (isEightDivisor(i)) ans++;
  }

  cout << ans << endl;

  return 0;
}