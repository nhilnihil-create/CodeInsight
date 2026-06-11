#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int a,b,c,ans;
  cin >> a >> b >> c;
  ans = b;
  if(a+b < c) ans += a+b+1;
  else ans += c;
  cout << ans << endl;
}