#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N, M;
  cin >> N >> M;
  int l = 1, r = N;
  for (int i = 1; i <= M; ++i) {
    int a, b;
    cin >> a >> b;
    l = max(l, a);
    r = min(r, b);
  }
  cout << max(0, r-l+1) << endl;
  return 0;
}