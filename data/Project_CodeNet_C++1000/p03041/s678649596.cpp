#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
const int INF = 1000000007;

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  s[k - 1] = (char)(s[k - 1] + 32);
  cout << s << endl;
}
