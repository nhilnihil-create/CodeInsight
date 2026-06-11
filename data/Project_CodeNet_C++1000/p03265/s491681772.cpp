#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int x = x2 - x1;
  int y = y2 - y1;

  cout << x2 - y << " " << y2 + x << " " << x1 - y << " " << y1 + x << endl;
}
