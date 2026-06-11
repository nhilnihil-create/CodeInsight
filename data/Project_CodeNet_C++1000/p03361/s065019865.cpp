#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

char maze[51][51];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
 
int main(){
  int h,w;
  cin >> h >> w;
  rep(i,h) rep(j,w) cin >> maze[i][j];
  for (int i = 0;i < h;i++){
    for (int j = 0; j < w;j++){
      bool can = false;
      if (maze[i][j] == '.') continue;
      for (int e = 0;e < 4;e++){
        int nx = i+dx[e], ny = j+dy[e];
        if (0 <= nx && nx < h && 0 <= ny && ny < w){
          if (maze[nx][ny] == '#') {
            can = true;
            break;
          }
        }
      }
      if (!can){
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;
  
  
  return 0; 
}

