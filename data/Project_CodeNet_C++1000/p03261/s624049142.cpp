#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
  int N;
  cin >> N;
  vector<string> w(N);

  cin >> w[0];

  int i = 1;
  do {
    bool ok = true;
    string word;
    cin >> word;
    if (w[i - 1].back() != word.front()) {
      ok = false;
    }
    if (find(w.begin(), w.end(), word) != w.end()) {
      ok = false;
    }

    if (!ok) {
      cout << "No" << endl;
      return 0;
    }

    w[i] = word;
    i++;    
  } while (i < N);

  cout << "Yes" << endl;

  return 0;
}
