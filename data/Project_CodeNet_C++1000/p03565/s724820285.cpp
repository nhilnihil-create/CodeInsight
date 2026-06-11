#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  string S,T;
  cin >> S >> T;
  int N = S.size(); 
  int M = T.size();
  vector<string> cand;
  for (int i = 0; i <= N - M; i++) {
    string str = S;
    bool can = true;
    for (int j = 0; j < M; j++) {
      if (S[i+j] == '?' || T[j] == S[i+j]) {
        str[i+j] = T[j];
      } else {
        can = false;
      }
    }
    if (can) {
      for (int i = 0; i < str.size(); i++) {
        if (str[i] == '?') {
          str[i] = 'a';
        }
      }
      cand.push_back(str);
    }
  }
  if (cand.size() == 0) {
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  string ans = cand[0];
  for (int i = 1; i < cand.size(); i++) {
    ans = min(ans,cand[i]);
  }
  cout << ans << endl;
  return 0;
}