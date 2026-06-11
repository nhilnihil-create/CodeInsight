#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
 
int main() {
  int n,m,c;
  int counter = 0;
  cin >> n >> m >> c;
  vector<int> b(m);
  vector<int> sum(n);
  vector<vector<int>> a(n, vector<int>(m));
  
  //bの取得
  for(int i = 0;i < m; i++) cin >> b[i]; 
  
  //aの取得
  for(int i = 0;i < n; i++){
     for(int j = 0;j < m; j++){
          cin >> a[i][j];
     }
     }
  
  //合計
  for(int i = 0;i < n; i++){
     for(int j = 0;j < m; j++){
          sum[i] += b[j] * a[i][j]; 
     }
     }
    
  for(int i = 0;i < n; i++){
        if(sum[i] + c > 0){
           counter++ ;
         }
     }

 cout << counter << endl;
  
}
