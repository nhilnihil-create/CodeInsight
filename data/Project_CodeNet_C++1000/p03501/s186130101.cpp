#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int n, a, b;
  cin >> n >> a >> b;

  int ans = min(a * n, b);
  cout << ans << endl;
}
