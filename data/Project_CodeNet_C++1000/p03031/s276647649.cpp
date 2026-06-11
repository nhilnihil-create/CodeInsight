#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define ll long long
#define mset(s, _) memset(s, _, sizeof s)
#define ALL(a) (a).begin(), (a).end()
using namespace std;

int main(void) {
  int N, M;
  cin >> N >> M;
  vector<int> s[M + 3];
  vector<int> p;

  rep(m, 1, M) {
    int K;
    cin >> K;
    rep(k, 1, K) {
      int S;
      cin >> S;
      S--;
      s[m - 1].push_back(S);
    }
  }

  rep(i, 1, M) {
    int P;
    cin >> P;
    p.push_back(P);
  }

  int ans = 0;

  rep(bit, 1, (1 << N)) {
    vector<bool> Sw;
    rep(i, 0, N - 1) {
      if (bit & (1 << i)) {
        // スイッチi on
        // cout << 1;
        Sw.push_back(1);
      } else {
        // cout << 0;
        Sw.push_back(0);
        // スイッチi off
      }
    }
    // cout << endl;

    bool mark = true;

    rep(m, 0, M - 1) {
      int on_sw_cnt = 0;
      for (auto si : s[m]) {
        if (Sw[si]) {
          on_sw_cnt++;
        }
      }

      // cout << m << ":" << on_sw_cnt << endl;

      if (on_sw_cnt % 2 != p[m]) {
        mark = false;
      }
    }

    // cout << "mark: " << mark << endl;

    if (mark) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
