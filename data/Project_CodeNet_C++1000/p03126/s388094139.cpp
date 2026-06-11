#include <bits/stdc++.h>
using namespace std;


int main() {
  int n, m; cin >> n >> m;
  int ans[m+1] = {0};
  for(int i = 0; i < n; i++){
    int k; cin >> k;
    for(int j = 0; j < k; j++){
      int a; cin >> a;
      ans[a]++;
    }
  }
  int cnt = 0;
  for(int i = 0; i < m+1; i++){
    if(ans[i] == n) cnt++;
  }
  cout << cnt << endl;
}
