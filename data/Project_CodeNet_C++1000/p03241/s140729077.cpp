#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n, m; cin >> n >> m;
  set<long long> d;
  d.insert(1); d.insert(m);
  for(int i = 2; i*i <= m; i++){
    if(m % i == 0){
      d.insert(i);
      d.insert(m/i);
    }
  }
  long long ans = 0;
  for(auto k: d){
    if(k*n > m) break;
    ans = max(ans, k);
  }
  cout << ans << endl;
}
  
  
      