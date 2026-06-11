#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline T intceil(T a, T b) { return (a + (b - 1)) / b; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const long long MOD = 1e9+7;
#define precout() cout << std::fixed << std::setprecision(20);
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
typedef complex<double> cd;
static const double pi = 3.141592653589793;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;
  int left = 0, right = n;

  cout << 0 << endl << flush;
  string leftT; cin >> leftT;
  if(leftT == "Vacant") {
    return 0;
  }

  while(true) {
    int mid = (left + right) / 2;
    cout << mid << endl << flush;
    string curT; cin >> curT;

    if(curT == "Vacant") {
      return 0;
    }

    if(((mid - left) % 2 == 0 && leftT == curT) || ((mid - left) % 2 == 1 && leftT != curT)) {
      left = mid;
      leftT = curT;
    } else {
      right = mid;
    }
  }
}
