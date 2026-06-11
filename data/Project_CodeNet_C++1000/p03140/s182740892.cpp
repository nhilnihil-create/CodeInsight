#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,ans = 0;
  string a,b,c;
  cin >> n >> a >> b >> c;
  for(int i = 0;i < n;i++){
    if(a[i] == b[i] && a[i] != c[i]) ans++;
    else if(a[i] == c[i] && a[i] != b[i]) ans++;
    else if(b[i] == c[i] && b[i] != a[i]) ans++;
    else if(a[i] != b[i] && b[i] != c[i] && a[i] != c[i]) ans += 2;
  }
  cout << ans << endl;
}
