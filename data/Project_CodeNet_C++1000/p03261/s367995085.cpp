#include <iostream>
#include <unordered_set>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  int N;
  cin >> N;
  char last_char;
  unordered_set<string> history;
  bool ok = true;
  rep(i, N) {
    string S;
    cin >> S;
    if (history.count(S)) ok = false;
    if (i != 0 && last_char != S[0]) ok = false;
    history.emplace(S);
    last_char = S.back();
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}