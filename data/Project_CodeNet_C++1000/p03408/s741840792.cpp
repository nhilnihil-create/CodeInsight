#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n;
  cin >> n;
  vector<string> va(n);
  rep(i, n) cin >> va[i];
  int m;
  cin >> m;
  vector<string> vb(m);
  rep(i, m) cin >> vb[i];

  int ans = 0;
  rep(i, n){
    int now = 0;
    string t = va[i];
    rep(j, n) if(va[j] == t) now++;
    rep(k, m) if(vb[k] == t) now--;
    if(now > ans) ans = now;
  }
  cout << ans << endl;
}
