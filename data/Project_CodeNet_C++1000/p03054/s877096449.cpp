#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
#define fst first
#define snd second

/* clang-format off */
template <class T, size_t D> struct _vec { using type = vector<typename _vec<T, D - 1>::type>; };
template <class T> struct _vec<T, 0> { using type = T; };
template <class T, size_t D> using vec = typename _vec<T, D>::type;
template <class T> vector<T> make_v(size_t size, const T& init) { return vector<T>(size, init); }
template <class... Ts> auto make_v(size_t size, Ts... rest) { return vector<decltype(make_v(rest...))>(size, make_v(rest...)); }
template <class T> inline void chmin(T &a, const T& b) { if (b < a) a = b; }
template <class T> inline void chmax(T &a, const T& b) { if (b > a) a = b; }
/* clang-format on */

vector<int> cand(int L, int R) {
  vector<int> S;
  for (int dx = -3; dx <= 3; dx++) S.push_back(L + dx);
  for (int dx = -3; dx <= 3; dx++) S.push_back(R + dx);
  return S;
}

bool solve(int W, int sx, const vector<int>& A, const vector<int>& B) {
  int N = A.size();
  int L = 1, R = W;
  for (int i = N - 1; i >= 0; i--) {
    int nL = W + 1, nR = 0;
    for (int x : cand(L, R)) {
      if (x < 1 || W < x) continue;
      bool ok = true;
      for (int a = 0; a < 2; a++) {
        int nx = x + A[i] * a;
        if (nx < 1 || W < nx) {
          ok = false;
          break;
        }
        bool found = false;
        for (int b = 0; b < 2; b++) {
          int nx = x + A[i] * a + B[i] * b;
          if (L <= nx && nx <= R) {
            found = true;
            break;
          }
        }
        ok &= found;
      }
      if (ok) {
        chmin(nL, x);
        chmax(nR, x);
      }
    }
    L = nL, R = nR;
  }
  return (L <= sx && sx <= R);
}

int main() {
#ifdef DEBUG
  ifstream ifs("in.txt");
  cin.rdbuf(ifs.rdbuf());
#endif
  int H, W, N;
  while (cin >> H >> W >> N) {
    int sr, sc;
    cin >> sr >> sc; 
    string S, T;
    cin >> S >> T;
    vector<int> ay(N), ax(N), by(N), bx(N);
    for (int i = 0; i < N; i++) {
      if (S[i] == 'L') ax[i] = -1;
      if (S[i] == 'R') ax[i] = +1;
      if (S[i] == 'U') ay[i] = -1;
      if (S[i] == 'D') ay[i] = +1;
    }
    for (int i = 0; i < N; i++) {
      if (T[i] == 'L') bx[i] = -1;
      if (T[i] == 'R') bx[i] = +1;
      if (T[i] == 'U') by[i] = -1;
      if (T[i] == 'D') by[i] = +1;
    }
    bool res = solve(H, sr, ay, by) && solve(W, sc, ax, bx);
    cout << (res ? "YES" : "NO") << endl;
  }
  return 0;
}
