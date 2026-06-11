#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int a[4] = {};
  rep(i,3) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    a[u]++; a[v]++;
  }
  int c = 0;
  rep(i,4) c = max(c,a[i]);
  cout << (c == 3? "NO" : "YES") << endl;
  return 0;
}