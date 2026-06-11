#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()
#define ADD(a, b) a = (a + b) % MOD

int H, W, N;
int sr, sc;
string S, T;
vector<int> mv_h, wh_h;
vector<int> mv_w, wh_w;

bool stay(int len, int start, vector<int> mv, vector<int> wh) {
  int mn = 0, mx = len - 1;
  RREP(i, mv.size()) {
    if (wh[i]) {  // 青木君のターン
      if (mv[i] == -1)
        mx = min(len - 1, mx + 1);
      else
        mn = max(0, mn - 1);
    } else {  // 高橋君のターン
      if (mv[i] == -1)
        mn++;
      else
        mx--;
    }
    if (mn > mx) return false;
  }
  return mn <= start && start <= mx;
}

int main() {
  cin >> H >> W >> N;
  cin >> sr >> sc;
  sr--, sc--;
  cin >> S >> T;
  REP(i, N) {
    if (S[i] == 'U') {
      mv_h.push_back(-1);
      wh_h.push_back(0);
    }
    if (S[i] == 'D') {
      mv_h.push_back(1);
      wh_h.push_back(0);
    }
    if (T[i] == 'U') {
      mv_h.push_back(-1);
      wh_h.push_back(1);
    }
    if (T[i] == 'D') {
      mv_h.push_back(1);
      wh_h.push_back(1);
    }
  }
  REP(i, N) {
    if (S[i] == 'L') {
      mv_w.push_back(-1);
      wh_w.push_back(0);
    }
    if (S[i] == 'R') {
      mv_w.push_back(1);
      wh_w.push_back(0);
    }
    if (T[i] == 'L') {
      mv_w.push_back(-1);
      wh_w.push_back(1);
    }
    if (T[i] == 'R') {
      mv_w.push_back(1);
      wh_w.push_back(1);
    }
  }
  if (stay(H, sr, mv_h, wh_h) && stay(W, sc, mv_w, wh_w))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}