#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 1; i <= (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;

  int ans = 0;
  rep(i, n){
    int count = 0;
    if (i % 2 == 0) continue;
    rep(j, i){
      if (i % j == 0) count++;
    }
    if (count == 8) ans++;
  }
  cout << ans << endl;
  return 0;
}