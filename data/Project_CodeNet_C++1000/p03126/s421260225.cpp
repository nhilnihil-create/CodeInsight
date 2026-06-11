#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  
  int res[m];
  memset(res,0,sizeof(res));
  
  for(int i = 0; i < n; ++i){
    int k;
    cin >> k;
    
    for(int j = 0; j < k; ++j){
      int x;
      cin >> x;
      
      ++res[x-1];
    }
  }
  
  int ans = 0;
  for(int i = 0; i < m; ++i){
    //cout << res[i] << endl;
    if(res[i] == n){
      ++ans;
    }
  }
  
  cout << ans << endl;
}