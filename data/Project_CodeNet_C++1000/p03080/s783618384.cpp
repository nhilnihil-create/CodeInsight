#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  string S;
  cin >>  N >> S;
  int r = 0;
  int b = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'R') {
      r++;
    } else {
      b++;
    }
  }
  if (r > b) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}