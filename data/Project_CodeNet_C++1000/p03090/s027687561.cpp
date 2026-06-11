// review
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> P;

int n;

void solve() {
  vector<P> v;
  for (int i=1;i<=n;i++) {
    for (int j=i+1;j<=n;j++) {
      if ((n & 1) && (j != n - i)) {
        v.push_back(P(i, j));
      } else if (!(n & 1) && (j != n - i + 1)) {
        v.push_back(P(i, j));
      }
    }
  }
  cout << v.size() << endl;
  for (int i = 0;i<v.size();i++) {
    cout << v[i].first << " " << v[i].second << endl;
  }
}

int main() {
  cin >> n;
  solve();
}
