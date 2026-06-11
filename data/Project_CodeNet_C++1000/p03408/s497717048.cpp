#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  
  cin >> N;
  vector<string> s(N);
  for (int i = 0; i < N; i++) cin >> s[i];
  
  cin >> M;
  vector<string> t(M);
  for (int i = 0; i < M; i++) cin >> t[i];
  
 int m = 0;
  for (int i = 0; i < N; i++) {
    int cnt_b = count(s.begin(), s.end(), s[i]);
    int cnt_r = count(t.begin(), t.end(), s[i]);
    int cnt = cnt_b - cnt_r;
    m = max(m, cnt);
  }
  cout << m << endl;
}