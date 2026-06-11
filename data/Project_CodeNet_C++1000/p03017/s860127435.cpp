#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;
  A--;
  B--;
  C--;
  D--;
  string S;
  cin >> S;
  S += "--";

  vector<bool> pathAC(N + 2, false);
  pathAC[A] = true;
  for (int i = A; i < C; ++i) {
    if (!pathAC[i]) continue;
    if (S[i + 1] == '.') pathAC[i + 1] = true;
    if (S[i + 2] == '.') pathAC[i + 2] = true;
  }

  vector<bool> pathBD(N + 2, false);
  pathBD[B] = true;
  for (int i = B; i < D; ++i) {
    if (!pathBD[i]) continue;
    if (S[i + 1] == '.') pathBD[i + 1] = true;
    if (S[i + 2] == '.') pathBD[i + 2] = true;
  }

  if (!pathAC[C] || !pathBD[D]) {
    cout << "No" << endl;
    return 0;
  }

  if (C > D) {
    bool swap = false;
    for (int i = B; i <= D; ++i) {
      if (S[i - 1] == '.' && S[i] == '.' && S[i + 1] == '.') {
        swap = true;
        break;
      }
    }
    if (!swap) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}