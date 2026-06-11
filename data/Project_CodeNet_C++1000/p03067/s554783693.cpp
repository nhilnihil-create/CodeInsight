#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int x = max(a,b);
  int y = min(a,b);
  if(y <= c && c <= x) puts("Yes");
  else puts("No");
  return 0;
}
