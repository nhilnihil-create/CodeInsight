#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> p(n);
  for(int i = 0; i < n; i++) cin >> p.at(i);
  
  int cnta = 0, ans = 0, cntb = 0;
  for(auto k : p){
    if(k <= a) cnta++;
    else if(k <= b) ans++;
    else cntb++;
  }
  
  ans = min(ans, min(cnta, cntb));
  
  cout << ans << endl;
}