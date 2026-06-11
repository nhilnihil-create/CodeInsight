#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  string S;
  cin >> S;
  int N = S.size();

  const string A = "AKIHABARA";
  int nA = A.size();
  if (nA < N) {
    cout << "NO" << endl;
    return 0;
  }

  int iS = 0;
  rep(iA, nA) {
    // cout << iA << ": " << A[iA] << endl;
    if (S[iS] == A[iA]) {
      iS++;
      if (iS == N) {
        if (iA < nA - 2) {
          cout << "NO" << endl;
          return 0;
        }
        break;
      }
    } else if (A[iA] != 'A') {
      cout << "NO" << endl;
      return 0;
    }
  }
  if (iS == N)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
