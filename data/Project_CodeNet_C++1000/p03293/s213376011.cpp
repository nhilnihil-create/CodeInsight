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
  int N = S.size();
  bool can = false;
  
  for (int i = 0; i < N; i++) {
    bool y = true;
    for (int j = 0; j < N; j++) {
      if (S[j] != T[(j+i)%N]) {
        y = false;
      }
    }
    if (y) {
      can = true;
    }
  }
  if (can) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}