#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int a, b;
  cin >> a >> b;

  if (a >= 13) cout << b << endl;
  else if (a >= 6 && a <= 12) cout << b / 2 << endl;
  else cout << 0 << endl;
}
