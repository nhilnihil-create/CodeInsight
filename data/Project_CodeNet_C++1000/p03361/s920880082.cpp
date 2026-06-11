#include<bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  cin >> h >> w;
  char a[h][w];
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cin >> a[i][j];
    }
  }
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(a[i][j] == '#' && a[i][j+1] != '#' && a[i][j-1] != '#' && a[i+1][j] != '#' && a[i-1][j] != '#'){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}