#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, h, w;
  cin >> n >> h >> w;
  
  int a, b, ans = 0;
  for(int i = 0; i < n; i++){
    cin >> a >> b;
    if(a >= h && b >= w) ans++;
  }
  
  cout << ans << '\n';
}