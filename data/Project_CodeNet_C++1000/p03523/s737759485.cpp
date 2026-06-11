#include <iostream>

using namespace std;

string A = "AKIHABARA";

int main() {
  string S;
  cin >> S;

  int i{}, j{}, n = S.size();
  while (i < n && j < (int)A.size()) {
    if (S[i] == A[j]) ++i, ++j;
    else if (A[j] == 'A') ++j;
    else break;
  }

  cout << (i == n && j > 7 ? "YES" : "NO") << endl;
}
