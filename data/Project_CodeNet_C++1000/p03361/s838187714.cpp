#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(50, vector<int>(50, 0));
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      char b;
      cin >> b;
      if(b=='#'){
        a[i][j] = 1;
      }
    }
  }
  int cnt = 0;
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      if(a[i][j]){
        bool ok = false;
        for(int k=0; k<4; k++){
          int nx = i + dx[k];
          int ny = j + dy[k];
          if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
          if(a[nx][ny]) ok = true;
        }
        if(!ok){
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
