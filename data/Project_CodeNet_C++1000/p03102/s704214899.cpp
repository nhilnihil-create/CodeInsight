#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,c;
  cin >> n >> m >> c;
  
  vector<int> b(m);
  for(int i = 0; i < m; ++i){
    cin >> b[i];
  }
  
  int a[n][m];
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      cin >> a[i][j];
    }
  }
  
  int res = 0;
  
  for(int i = 0; i < n; ++i){
    int p = 0;
    for(int j = 0; j < m; ++j){
      p += a[i][j] * b[j];
    }
    p += c;
    
    if(p > 0){
      ++res;
    }
  }
  
  cout << res;
}