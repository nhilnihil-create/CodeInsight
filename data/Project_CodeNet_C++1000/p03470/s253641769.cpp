#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  set<int> d;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    d.insert(x);
  }
  cout << d.size() << endl;
  return 0;
}