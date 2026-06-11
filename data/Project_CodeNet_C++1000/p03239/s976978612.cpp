#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, T;
  cin >> n >> T;
  vector<int> c(n);
  vector<int> t(n);
  for (int i=0 ; i<n ; i++)
    cin >> c.at(i) >> t.at(i);
  
  for (int i=0 ; i<n ; i++){
    if (t.at(i) > T)
      c.at(i) = -1;
  }
  
  sort(c.begin(), c.end());
  
  int ans, judge = 0;
  for (int i=0 ; i<n ; i++){
    if (c.at(i) > 0){
      judge = 1;
      ans = c.at(i);
      break;
    }
  }
  
  if (judge == 1)
    cout << ans << endl;
  else
    cout << "TLE" << endl;
}