#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int a, b, c;
  cin >> a >> b >> c;

  cout << 10 * max({a, b, c}) + a + b + c - max({a, b, c}) << endl;
}
