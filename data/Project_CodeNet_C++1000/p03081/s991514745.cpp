#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
int N, Q;
string S;
vector<char> T;
vector<char> D;

bool isOut(int mid, bool zero) {
  int pos = mid;
  bool out = false;
  rep(i, Q) {
    if (S[pos] == T[i]) {
      pos += (D[i] == 'L') ? -1 : +1;
    }
    if (zero) {
      if (pos < 0) {
        out = true;
        break;
      }
    } else {
      if (N <= pos) {
        out = true;
        break;
      }
    }
  }
  return out;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin >> N >> Q;
  cin >> S;
  T.resize(Q);
  D.resize(Q);
  rep(i, Q) { cin >> T[i] >> D[i]; }

  int left = 0;
  int right = min(Q, N);
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (isOut(mid, true)) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  int answer = N;
  answer -= left;

  left = N - min(Q, N);
  right = N;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (isOut(mid, false)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  answer -= (N - left);
  cout << answer << endl;
  return 0;
}
