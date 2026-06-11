#include <bits/stdc++.h>
using namespace std;
using pp=pair<int, int>;

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> m(N);
  for(int i=0; i<N; i++) {
    cin >> m[i];
    X-=m[i];
  }
  sort(m.begin(), m.end());
  cout << N+X/m[0] << endl;
}
