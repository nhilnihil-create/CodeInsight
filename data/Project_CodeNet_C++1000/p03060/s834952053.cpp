#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  vector<int> c(n);
  rep(i,n) cin >> v[i];
  rep(i,n) cin >> c[i];
  int ans = 0;
  for(int i = 0; i < (1 << n); i++){
    bitset<21> s(i);
    int x = 0;
    int y = 0;
    rep(j,n){
      if(s.test(j)){
        x += v[j];
        y += c[j];
      }
    }
    ans = max(ans,x -y);
  }
  cout << ans << endl;
}
 