#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> blue(n);
  for(int i=0; i<n; i++) cin >> blue[i];
  sort(blue.begin(), blue.end());
  
  int m;
  cin >> m;
  vector<string> red(m);
  for(int i=0; i<m; i++) cin >> red[i];
  
  int count = 0, ans = 0;
  for(int i=0; i<n; i++) {
    string x = blue[i]; 
    auto p = find(red.begin(), red.end(), x);
    if(p!=red.end()) {
      count--;
      red.erase(p);
    }
    count++;
    if(i==n-1) {
      if(ans<count) ans = count;
      break;
    } 
    if(blue[i]!=blue[i+1]) {
      if(ans<count) ans = count;
      count = 0;
    }
  }
  cout << ans << endl;
  return 0;
}