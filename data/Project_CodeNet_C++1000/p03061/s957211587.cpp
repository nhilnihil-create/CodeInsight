#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int NIL = -1;
const int INF = (1<<21);
const long long MOD = 1e9+7;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}

int main() {
  int N; cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; ++i) cin >> a[i];

  vector<int> left(N+1, 0), right(N+1,0);
  for (int i = 0; i < N; ++i) left[i+1] = gcd(left[i], a[i]);
  for (int i = N-1; i >= 0; --i) right[i] = gcd(right[i+1], a[i]);

  int res = 0;
  for (int i = 0; i < N; ++i) {
    int l = left[i];
    int r = right[i+1];
    chmax(res, gcd(l, r));
  }
  cout << res << endl;
}
