#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int a, b, c;
  cin >> a >> b >> c;

  int ans = min(c, b / a);
  cout << ans << endl;
}
