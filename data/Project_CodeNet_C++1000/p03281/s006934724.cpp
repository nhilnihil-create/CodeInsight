#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<int> div(n+1);
  int ans = 0;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if (i % j == 0) div[i]++;
    }
  }
  for(int i=1; i<=n; i++) {
    if (div[i] == 8 && i % 2 == 1) ans++;
  }
  cout << ans << endl;
  return 0;
}