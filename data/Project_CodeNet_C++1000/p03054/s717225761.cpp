#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const long long MOD = 1e9+7;
template<typename T> inline void add(T& a, T b) { a += b; if (a >= MOD) a -= MOD; }

int H, W, N;
int ix, iy;
string S, T;

bool solve() {
    // left, right
    int left = 0, right = W;
    if (S[N-1] == 'L') ++left;
    if (S[N-1] == 'R') --right;
    for (int i = N-2; i >= 0; --i) {
        if (T[i] == 'L') right = min(right+1, W);
        else if (T[i] == 'R') left = max(0, left-1);
        if (S[i] == 'L') left = left + 1;
        else if (S[i] == 'R') right = right - 1;
        if (left >= right) return false;
    }
    if (iy < left || iy >= right) return false;

    // up, down
    left = 0, right = H;
    if (S[N-1] == 'U') ++left;
    if (S[N-1] == 'D') --right;
    for (int i = N-2; i >= 0; --i) {
        if (T[i] == 'U') right = min(right+1, H);
        else if (T[i] == 'D') left = max(0, left-1);
        if (S[i] == 'U') left = left + 1;
        else if (S[i] == 'D') right = right - 1;
        if (left >= right) return false;
    }
    if (ix < left || ix >= right) return false;

    return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  while (cin >> H >> W >> N >> ix >> iy >> S >> T) {
    --ix, --iy;
    if (solve()) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
