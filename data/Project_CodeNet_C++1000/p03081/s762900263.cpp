#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

int N,Q;
string S;
vector<pair<char,char>> Query;

// 左に落ちるとき-1
// 落ちないとき0
// 右に落ちるとき1
int Check(int ind) {
  int now = ind;
  for (int i = 0; i < Q; i++) {
    if (S[now] == Query[i].fi) {
      if (Query[i].se == 'L') {
        now--;
      } else {
        now++;
      }
    }
    if (now == -1) {
      return -1;
    }
    if (now == N) {
      return 1;
    }
  }
  return 0;
}
int main() {
  cin >> N >> Q;
  cin >> S;
  int L = 0;
  int R = 0;
  for (int i = 0; i < Q; i++) {
    char c,d;
    cin >> c >> d;
    Query.emplace_back(c,d);
  }
  int left = -1;
  int right = N;
  while (right - left > 1) {
    int mid = (left + right) / 2;
    if (Check(mid) == -1) {
      left = mid;
    } else {
      right = mid;
    }
  }
  L = right;
  left = -1;
  right = N;
  while (right - left > 1) {
    int mid = (left + right) / 2;
    if (Check(mid) == 1) {
      right = mid;
    } else {
      left = mid;
    }
  }
  R = left;
  cout << R - L + 1 << endl;
  return 0;
}