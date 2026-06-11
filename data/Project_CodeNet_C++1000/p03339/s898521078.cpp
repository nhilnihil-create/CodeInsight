#include<bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  string s; cin >> s;
  int E = count(s.begin(), s.end(), 'E');
  int W = 0;
  int res = N;
  for (int i = 0; i < N; i++) {
    if (s[i] == 'E') E--;
    res = min(res, W + E);
    if (s[i] == 'W') W++;
  }
  cout << res << endl;
}