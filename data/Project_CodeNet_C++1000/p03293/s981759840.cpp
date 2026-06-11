#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (int i = (f); i < (int)(n); i++)
#define repe(i, f, n) for (int i = (f); i <= (int)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

const int INF = 1001001001;

int main() {
  string S, T;
  cin >> S >> T;
  int n = S.size();
  rep(i, 0, n) {
    char tail = S[n - 1];
    string r = tail + S.substr(0, n - 1);
    if (r == T) {
      cout << "Yes" << endl;
      return 0;
    }
    S = r;
  }

  cout << "No" << endl;
  return 0;
}
