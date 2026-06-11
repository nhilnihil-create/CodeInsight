#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, char> pchar;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define FORR(i, a, b) for (int i = (int)(b)-1; i >= (int)(a); i--)

#define CHMIN(a, b) (a) = min((a), (b))
#define CHMAX(a, b) (a) = max((a), (b))

#define DEBUG(x) cout << #x << ": " << (x) << endl

//２分探索　単調的に範囲が取れることに着目して思いつくべき。

int check(const string &s, const vector<pchar> &td, int pos) {
  //範囲for文という表現　配列やコンテナを簡潔に扱うためのfor文の別表現である。　
  // 範囲for文は配列または、begin()およびend()で表される範囲内の全ての要素に対して、処理を実行する。
  for (auto c : td) {
    if (c.first == s[pos]) {  //クエリに該当するものだった場合
      if (c.second == 'R')
        pos++;
      else if (c.second == 'L')
        pos--;

      if (pos < 0)
        return -1;
      else if (s.length() <= pos)
        return 1;
    }
  }

  return 0;
}

int main() {
  int N, Q;
  cin >> N >> Q;

  string s;
  cin >> s;

  vector<pchar> td(Q);
  FOR(i, 0, Q) cin >> td[i].first >> td[i].second;

  int fall_left, fall_right;

  //[low,high) //[ok,ng)
  int low, mid, high;
  low = 0;
  high = N;

  while (high - low > 1) {  //右側に落ちる下限
    mid = (high + low) / 2;
    if (check(s, td, mid) == 1)
      high = mid;  //落ちた
    else
      low = mid;
  }

  fall_right = (N - 1) - low;

  low = 0;
  high = N;
  //(low,high]

  while (high - low > 1) {  //左側に落ちる上限
    mid = (high + low) / 2;
    if (check(s, td, mid) == -1)
      low = mid;  //落ちた場合
    else
      high = mid;
  }

  fall_left = high;

  cout << N - (fall_left + fall_right) << endl;
}
