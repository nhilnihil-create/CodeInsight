#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  int a[3];
  rep(i, 3) cin >> a[i];
  int ans = 0;
  if(a[0] == a[1] && a[1] == a[2]) cout << 0 << endl;
  else{
    sort(a, a + 3);
    if((a[2] - a[1]) % 2 == 0 && (a[2] - a[0]) % 2 == 0) {
      ans += (a[2] - a[1]) / 2;
      ans += (a[2] - a[0]) / 2;
    }
    else if((a[2] - a[1]) % 2 == 1 && (a[2] - a[0]) % 2 == 1) {
      ans++;
      a[1]++;
      a[0]++;
      ans += (a[2] - a[1]) / 2;
      ans += (a[2] - a[0]) / 2;
    }
    else if((a[2] - a[1]) % 2 == 0 ) {
      ans++;
      a[2]++;
      a[1]++;
      ans += (a[2] - a[1]) / 2;
      ans += (a[2] - a[0]) / 2;
    }
    else{
      ans++;
      a[2]++;
      a[0]++;
      ans += (a[2] - a[1]) / 2;
      ans += (a[2] - a[0]) / 2;
    }
    cout << ans << endl;
  }
    
  return 0;
}
