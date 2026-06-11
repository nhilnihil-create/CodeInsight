#include <bits/stdc++.h>
using namespace std;
#define SORT(a) sort((a).begin(), (a).end())
#define RSORT(a) reverse((a).begin(), (a).end())
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(a) ((a).begin(), (a).end())
typedef long long ll;
const long long INF = 1LL << 60;
// const int INF=1010101010;
// using Graph = vector<vector<int>>;

int main() {
  long long n, k;
  cin >> n >> k;
  long long cnt = 0;
  if (k == 0)
    cout << n * n << endl;
  else {
    for (int i = k + 1; i <= n; i++) {
      cnt += n / i * (i - k);
      cnt += max(n % i - k + 1, (long long)0);
    }
    cout << cnt << endl;
    return 0;
  }
}