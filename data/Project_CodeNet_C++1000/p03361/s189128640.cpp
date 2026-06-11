#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b;
  cin >> a >> b;
  char vec[a][b];
  for(int i = 0;i < a;i++){
    for(int j = 0;j < b;j++){
      cin >> vec[i][j];
    }
  }
  int count = 0;
  
  for(int i = 0;i < a;i++){
    for(int j = 0;j < b;j++){
      if(vec[i][j] == '#' && vec[i][j-1] == '.' && vec[i][j+1] == '.' && vec[i-1][j] == '.' && vec[i+1][j] == '.'){
        count++;
      }
    }
  }
  
  if(count == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}