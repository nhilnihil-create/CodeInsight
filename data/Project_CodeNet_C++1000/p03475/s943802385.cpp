#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> c(n), s(n), f(n);
  for(int i = 0; i < n-1; i++) cin >> c.at(i) >> s.at(i) >> f.at(i);
  
  for(int i = 0; i < n; i++){
    int ans = s.at(i) + c.at(i);
    for(int j = i+1; j < n-1; j++){
      if(ans < s.at(j)) ans = s.at(j) + c.at(j);
      else ans = (ans - s.at(j) + f.at(j) - 1) / f.at(j) * f.at(j) + s.at(j) + c.at(j);
    }
    cout << ans << endl;
  }
}