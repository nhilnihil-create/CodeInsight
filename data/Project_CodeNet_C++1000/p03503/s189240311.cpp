#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define _GLIBCXX_DEBUG

signed main() {
  int N; cin >> N;
  vector<vector<int>> F(N, vector<int>(10)), P(N, vector<int>(11));
  rep(i, N) rep(j, 10) cin >> F[i][j];
  rep(i, N) rep(j, 11) cin >> P[i][j];
  
  priority_queue<int> q;
  
  bitset<10> x;
  rep(i, 1023) {
    x = i+1;
    int a = 0;
    rep(j, N) {
      int c = 0;
      rep(k, 10) if(x[k]*F[j][k] == 1) c++;
      a += P[j][c];
    }
    q.push(a);
  }
  

  cout << q.top() << endl;
}