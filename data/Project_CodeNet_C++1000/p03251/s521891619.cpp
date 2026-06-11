// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
//  cout.precision(15); cout << fixed;

int main() {
  int n, m, x, y; cin >> n >> m >> x >> y;
  vector<int> X(n), Y(m);
  loop(i,0,n) cin >> X[i];
  loop(i,0,m) cin >> Y[i];
  X.push_back(x);
  Y.push_back(y);
  sort(X.rbegin(), X.rend());
  sort(Y.begin(), Y.end());
  if (X[0] < Y[0]) cout << "No War" << endl;
  else cout << "War" << endl;
  return 0;
}
