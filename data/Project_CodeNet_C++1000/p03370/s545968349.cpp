#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;

  vector<int> m(N);
  rep(i, 0, N) cin >> m.at(i);

  sort(m.begin(), m.end());

  int temp = 0;
  rep(i, 0, N) temp += m.at(i);
  cout << N+((X-temp)/m.front()) << endl;
}
