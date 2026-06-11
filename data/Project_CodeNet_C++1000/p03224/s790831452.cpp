#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;

  bool flag = false;
  int n;
  for ( int i = 1; i <= 100001; i++ ) {
    if ( N == i*(i+1)/2 ) {
      flag = true;
      n = i;
      break;
    }
  }

  if ( !flag ) {
    cout << "No" << endl;
    return 0;
  }

  vector<int> ans[n+1];  
  int p = 1;
  for ( int i = 0; i < n; i++ ) {
    for ( int j = 0; j < n-i; j++ ) {
      ans[i].emplace_back(p++);      
    }
    int m = ans[i].size();    
    for ( int j = m-1; j >= m-(n-i); j-- ) {
      ans[i+((m-1)-j)+1].emplace_back(ans[i][j]);      
    }
  }

  cout << "Yes" << endl;
  cout << n+1 << endl;
  for ( int i = 0; i < n+1; i++ ) {
    cout << n << " ";
    for ( int j = 0; j < ans[i].size(); j++ ) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  
  return 0;
}
