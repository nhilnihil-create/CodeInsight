#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll mod = 998244353;
const int MAX = 510000;

int main() {
  vector<char> alphabet;
  for (char c='a'; c<='z'; c++) alphabet.push_back(c);
  string S;
  cin >> S;
  map<char, bool> dic; // 登場した英小文字
  for (int i=0; i<S.size(); i++) dic[S[i]] = true;
  if (S.size()==26) {
    bool can = false;
    for (int i=0; i<S.size()-1; i++) {
      if (S[i]<S[i+1]) {
        can = true;
        break;
      }
    }
    if (!can) cout << -1 << endl;
    else {
      string T = S;
      bool end = false;
      do {
        if (S>T) {
          for (int i=0; i<S.size(); i++) {
            cout << S[i];
            if (S[i]!=T[i]) {
              cout << endl;
              end = true;
              break;
            }
          }
        }
        if (end) break;
      } while (next_permutation(S.begin(), S.end()));
    }
  }
  else {
    for (int i=0; i<alphabet.size(); i++) {
      if (!dic.count(alphabet[i])) {
        cout << S << alphabet[i] << endl;
        break;
      }
    }
  }
}