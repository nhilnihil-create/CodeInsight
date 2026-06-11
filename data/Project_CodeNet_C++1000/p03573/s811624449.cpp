#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int a, b, c;
  cin >> a >> b >> c;

  if (a == b) cout << c << endl;
  if (b == c) cout << a << endl;
  if (c == a) cout << b << endl;
}
