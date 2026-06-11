#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T &a, T b) {if (a < b) {a = b;return 1;}return 0;}
template<class T> inline bool chmin(T &a, T b) {if (a > b) {a = b;return 1;}return 0;}

int main() {
  int n;
  cin >> n;
  int l = n / 100;
  int r = n % 100;
  if (1 <= l && l <= 12) {
    if (1 <= r && r <= 12) cout << "AMBIGUOUS" << endl;
    else cout << "MMYY" << endl;
  } else {
    if (1 <= r && r <= 12) cout << "YYMM" << endl;
    else cout << "NA" << endl;
  }
}
