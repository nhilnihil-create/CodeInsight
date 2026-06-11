#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {
  vector<int> x(4);
  vector<int> y(4);
  cin >> x[0] >> y[0] >> x[1] >> y[1];

  int dx = (x[1] - x[0]);
  int dy = (y[1] - y[0]);

  cout << x[1] - dy << " " << y[1] + dx << " ";
  cout << x[1] - dy - dx << " " << y[1] + dx - dy << endl;


	return 0;
}

