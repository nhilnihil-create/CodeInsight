#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,ans = 0;
  string a,b,c;
  cin >> n >> a >> b >> c;
  for(int i = 0;i < n;i++){
    int cnt = 0;
    if(a[i] == b[i]) cnt++;
    if(b[i] == c[i]) cnt++;
    if(c[i] == a[i]) cnt++;
    if(cnt == 0) ans += 2;
    if(cnt == 1) ans++;
  }
  cout << ans << endl;
}
