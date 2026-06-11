#include <bits/stdc++.h>
#define rep(i,n) for<int i=0; i<(n); ++i>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int a,b;
  cin >> a >> b;
  int ans = 0;
  ans = max(max((a + (a-1)), (a + b)), b + (b-1));
  cout << ans << endl;
  return 0;
}