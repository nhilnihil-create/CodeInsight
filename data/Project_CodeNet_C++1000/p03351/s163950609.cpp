#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  bool isOK = abs(a - c) <= d || (abs(a - b) <= d && abs(b - c) <= d);
  if (isOK) cout << "Yes" << endl;
  else cout << "No" << endl;
}
