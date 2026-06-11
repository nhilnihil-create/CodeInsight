#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int NIL = -1;
const long long INF = 1LL << 60;
const long long MOD = 1e9+7;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

int main() {
  string S; cin >> S;
  int a = 10 * (S[0] - '0') + (S[1] - '0');
  int b = 10 * (S[2] - '0') + (S[3] - '0');
  if (a >= 1 && a <= 12) {
    if (b >= 1 && b <= 12) {
      cout << "AMBIGUOUS" << endl;
    }
    else {
      cout << "MMYY" << endl;
    }
  }
  else {
    if (b >= 1 && b <= 12) {
      cout << "YYMM" << endl;
    }
    else cout << "NA" << endl;
  }
}
