#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  string prev, curr;
  set<string> hist;
  cin >> prev;
  hist.insert(prev);
  rep(i, N - 1) {
    cin >> curr;
    if (prev[prev.size() - 1] != curr[0] || hist.count(curr) > 0) {
      cout << "No" << endl;
      return 0;
    }
    hist.insert(curr);
    prev = curr;
  }
  cout << "Yes" << endl;
}