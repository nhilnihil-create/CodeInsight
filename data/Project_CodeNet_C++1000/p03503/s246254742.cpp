#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  int n;
  cin >> n;
  vector<vector<int>> f(n, vector<int>(10));
  for(int i=0; i<n; i++){
    for(int j=0; j<10; j++){
      cin >> f[i][j];
    }
  }
  vector<vector<int>> p(n, vector<int>(11));
  for(int i=0; i<n; i++){
    for(int j=0; j<11; j++){
      cin >> p[i][j];
    }
  }
  int l = 1 << 10;
  int ans = -1000000009;
  for(int i=1; i<l; i++){
    int m[n]={};
    int tmp=0;
    for(int bit=0; bit<10; bit++){
      if(i&(1<<bit)){
        for(int j=0; j<n; j++){
          m[j] += f[j][bit];
        }
      }
    }
    for(int j=0; j<n; j++){
      tmp += p[j][m[j]];
    }
    
    ans = max(ans, tmp);
    
  }
  cout << ans << endl;
  return 0;
}
