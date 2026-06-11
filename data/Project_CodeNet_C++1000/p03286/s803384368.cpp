#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  ll N;
  cin >> N;
  if (N == 0) {
    cout << 0 << endl;
    return 0;
  }
  string S;
  ll i = 1;
  while (N != 0) {
    if (N % (i * -2) != 0) {
      S.push_back('1');
      N -= i;
    } else {
      S.push_back('0');
    }
    i *= -2;
  }
  reverse(S.begin(), S.end());
  cout << S << endl;
}