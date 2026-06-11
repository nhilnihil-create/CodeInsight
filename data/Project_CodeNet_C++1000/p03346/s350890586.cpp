#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x--;
    p[x] = i;
  }
  int t = 1, ans = 1;
  for (int i = 1; i < n; i++) {
    if (p[i] > p[i - 1]) {
      t++;
    } else {
      t = 1;
    }
    ans = max(ans, t);
  }
  cout << n - ans << '\n';
  return 0;
}
