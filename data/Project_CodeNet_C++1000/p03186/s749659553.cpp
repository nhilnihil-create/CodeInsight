#include <bits/stdc++.h>
#define P pair<int, int>

using namespace std;
const int INF=1e5;

int main(){
  long long a, b, c;
  cin >> a >> b >> c;
  long long ans=0;
  ans += min(c, a);
  c -= min(c, a);
  ans += min(b, c);
  c -= min(b, c);
  ans += b;
  ans += min(c, 1LL);
  cout << ans << endl;
}

