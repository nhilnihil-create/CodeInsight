#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N; cin >> N;
  map<string, int> m;
  char last;
  bool ok = true;
  rep(i,N) {
    string w; cin >> w;
    if (i > 0 && w[0] != last) ok = false;
    last = w.back();
    m[w]++;
    if (m[w] > 1) ok = false; 
  }
  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}