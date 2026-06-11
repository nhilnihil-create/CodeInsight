#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ce = 0;
  int cw = 0;
  rep (i, n) if (s[i] == 'E') ++ce;

  int ans = 3e5 + 1;
  rep (i, n){
    if (s[i] == 'E') --ce;
    if ((i-1 >= 0) && (s[i-1] == 'W')) ++cw;
    int temp = ce + cw;
    if (ans > temp) ans = temp;
  }
  cout << ans << endl;
  return 0;
}