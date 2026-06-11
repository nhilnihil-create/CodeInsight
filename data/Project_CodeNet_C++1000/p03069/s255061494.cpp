#include <iostream>
#include <vector>
using namespace std;
template <class T> inline bool chmin(T& a, T b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
}

int INF = 1e9;
int main() {
  int N;
  cin >> N;
  vector<int> l2r(N, 0);
  vector<int> r2l(N, 0);
  string S;
  cin >> S;
  { // 先頭からお尻への黒の累積和
    int count = 0;
    for(int i = 0; i < S.size(); ++i) {
      if(S[i] == '#') {
        count++;
      }
      l2r[i] = count;
    }
  }
  { // お尻から先頭への白の累積和
    int count = 0;
    for(int i = S.size() - 1; i >= 0; --i) {
      if(S[i] == '.') {
        count++;
      }
      r2l[i] = count;
    }
  }
  int ans = INF;
  for(int i = 0; i < S.size(); ++i) {
    if(0 <= i - 1 && i + 1 < S.size()) {
      chmin(ans, l2r[i - 1] + r2l[i + 1]);
    } else if(i - 1 < 0) {
      chmin(ans, r2l[i + 1]);
    } else if(i + 1 >= S.size()) {
      chmin(ans, l2r[i - 1]);
    }
  }
  cout << ans << endl;
  return 0;
}