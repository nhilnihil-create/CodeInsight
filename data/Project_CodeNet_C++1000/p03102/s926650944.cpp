#include <bits/stdc++.h>
using namespace std;

int main() {

 int n,m,c;
  cin >> n >> m >> c;

  vector<int> times(m);
  for(int i = 0; i < m; i++) {
    cin >> times.at(i);
  }
  
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int sum = 0;
    for(int j =0; j < m; j++) {
      int temp;
      cin >> temp;
      sum += temp * times.at(j);
    }
    if(sum + c > 0) {
      ans ++;
    }
  }
 cout << ans << endl;
  
 return 0; 
}