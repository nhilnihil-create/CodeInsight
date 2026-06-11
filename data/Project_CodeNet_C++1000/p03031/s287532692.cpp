#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> s(n, 0);
  int k;
  rep(i, m){
    cin >> k;
    rep(j, k){
      int a;
      cin >> a;
      s[a-1] |= (1 << i);
    }
  }
  int p;
  rep(i, m){
    int b;
    cin >> b;
    p |= (b << i);
  }
  int ans = 0;
  int l = 0;
  rep(i, (1 << n)){
    l = 0;
    rep(j, n){
      if (i & (1 << j)){
        l ^= s[j];
      }
    }
    if (l == p) ans++;
  }
  cout << ans << endl;
  return 0;
}