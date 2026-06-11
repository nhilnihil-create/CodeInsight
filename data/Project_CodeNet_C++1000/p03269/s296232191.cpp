#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int L;
  cin >> L;
  bool f = true;
  int N;
  int sum = 0;
  vector<pair<P,int>> G;
  for (int bit = 25; bit >= 0; bit--) {
    if ((1 << bit) & L) {
      if (f) {
        f = false;
        N = bit+1;
        for (int i = 1; i < N; i++) {
          G.push_back(make_pair(make_pair(i,i+1),0));
          G.push_back(make_pair(make_pair(i,i+1),(1 << i-1)));
        }
      } else {
        G.push_back(make_pair(make_pair(bit+1,N),sum));
      }
      sum += (1 << bit);
    }
  }
  int M = (int)G.size();
  cout << N << " " << M << endl;
  for (int i = 0; i < M; i++) {
    cout << G[i].F.F << " " << G[i].F.S << " " << G[i].S << endl;
  }
  return 0;
}