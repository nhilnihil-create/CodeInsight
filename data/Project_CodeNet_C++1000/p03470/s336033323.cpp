#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> p;
typedef long long ll;
const int inf = 1000000007;

int main() {
  int n;
  cin >> n;
  set<int> s;
  rep(i, n) {
    int d;
    cin >> d;
    s.insert(d);
  }
  cout << s.size() << endl;
  return 0;
}