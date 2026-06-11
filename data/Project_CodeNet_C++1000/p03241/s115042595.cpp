#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;


int main() {
  int n, m;
  cin >> n >> m;
  set<int> a;
  for(int i = 1; i*i <= m; i++) {
    if(m%i!=0) continue;
    a.insert(i);
    a.insert(m/i);
  }
  for(int i = m/n; i > 0; i--) {
    if(a.count(i)) {
      cout << i << endl;
      return 0;
    }
  }
}