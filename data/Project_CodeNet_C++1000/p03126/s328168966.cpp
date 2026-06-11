#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  
  vector<int> f(m);
  
  rep(i,n) {
    int k;
    cin >> k;
    rep(j,k) {
      int a;
      cin >> a;
      f[a-1]++;
    }
  }
  
  int ans = 0;
  rep(i,m) if (f[i]==n) ans++;
  
  cout << ans << endl;
}