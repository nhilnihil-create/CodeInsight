#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

main(){
  int h,w;cin >> h >> w;
  string str[50];for(int i=0;i<h;i++) cin >> str[i];
  
  const int dx[8] = {1,0,-1,0,1,-1,-1,1};
  const int dy[8] = {0,1,0,-1,1,1,-1,-1};
  
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(str[i][j] == '#') {
        cout << '#';
        continue;
      }
      
      int cnt=0;
      
      if(str[i][j] == '.'){
        for(int k=0;k<8;k++){
          const int ni = i + dy[k];
          const int nj = j + dx[k];
          if(ni < 0 || ni >=h) continue;
          if(nj < 0 || nj >=w) continue;
          
          if(str[ni][nj] == '#') cnt++;
        }
        cout << cnt;
      }
    }
    cout << endl;
  }
  return 0;
} 