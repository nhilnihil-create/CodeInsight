#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  string S,T;
  cin >> S >> T;
  bool ans = true;
  int count[26][26];
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      count[i][j] = 0;
    }
  }

  for (int i = 0; i < (int)S.size(); i++) {
    int c = S[i] - 'a';
    int d = T[i] - 'a';
    count[c][d]++;
  }

  for (int i = 0; i < 26; i++) {
    int cnt = 0;
    for (int j = 0; j < 26; j++) {
      if (count[i][j] > 0) {
        cnt++;
      }
    }
    if (cnt >= 2) {
      ans = false;
    }
  }
  for (int i = 0; i < 26; i++) {
    int cnt = 0;
    for (int j = 0; j < 26; j++) {
      if (count[j][i] > 0) {
        cnt++;
      }
    }
    if (cnt >= 2) {
      ans = false;
    }
  }

  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl; 
  return 0;
}