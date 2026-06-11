#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
  string S, T;
  cin >> S >> T;

  for (int i = 0; i < S.size(); ++i) {
    if (S == T) {
      cout << "Yes" << endl;
      return 0;
    }

    string temp = "";
    temp.append(1, S[S.size() - 1]);
    temp += S.substr(0, S.size() -1);
    S = temp;
  }

  cout << "No" << endl;
  
  return 0;
}