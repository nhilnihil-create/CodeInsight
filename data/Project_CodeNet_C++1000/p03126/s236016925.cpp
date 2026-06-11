#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  bool a[n][m];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      a[i][j] = false;
    }
  }
  for(int i = 0; i < n; i++){
    int k;
    cin >> k;
    for(int j = 0; j < k; j++){
      int p;
      cin >> p;
      a[i][p-1] = true;
    }
  }
  int ans = 0;
  for(int j = 0; j < m; j++){
    bool flag = true;
    for(int i = 0; i < n; i++){
      if(a[i][j] == false) flag = false;
    }
    if(flag) ans++;
  }
  cout << ans << endl;
}