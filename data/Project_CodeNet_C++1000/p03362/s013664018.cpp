#include <bits/stdc++.h>
using namespace std;
#define SORT(a) sort((a).begin(), (a).end())
#define RSORT(a) reverse((a).begin(), (a).end())
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
const long long INF = 1LL << 60;
// const int INF=1010101010;
using Graph = vector<vector<int>>;

int main() {
  int MAX = 555555;
  vector<bool> is_prime(MAX, 1);
  is_prime[0] = 0, is_prime[1] = 0;
  for (int i = 2; i < MAX; ++i) {
    if (!is_prime[i]) continue;
    for (int j = i * 2; j < MAX; j += i) is_prime[j] = 0;
  }
  int n;
  cin >> n;
  int cnt = 0;

  for (int i = 0; i < 555555; i++) {
    if (is_prime[i]) {
      if (i % 5 == 1) {
        cout << i << " ";
        cnt++;
        if (cnt == n) break;
      }
    }
  }
  cout << endl;

  return 0;
}