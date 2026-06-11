#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> a, b(N);
  rep(i,0,N-1) cin >> b[i];

  for (int i = 0; i < N; ++i) {
    for (int j = N - i - 1; 0 <= j; --j) {
      if (b.at(j) == j + 1) {
        a.push_back(b.at(j));
        b.erase(b.begin() + j);
        break;
      }
    }
  }

  if (0 < b.size())
  {
    cout << -1 << endl;
    return 0;
  }

  for (auto it = a.rbegin(); it != a.rend(); ++it)
    cout << *it << endl;

  return 0;
}
