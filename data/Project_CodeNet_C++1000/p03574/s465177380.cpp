#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)
typedef long long ll;


int main() {
  int h, w;
  cin >> h >> w;
  char mine[h][w];
  char ans[h][w];
  int dx[3] = {-1, 0, 1}, dy[3] = {-1, 0, 1};
  rep(i, h){
    rep(j, w){
      cin >> mine[i][j];
      ans[i][j] = mine[i][j];
      
    }
  }

  rep(i, h){
    rep(j, w){
      if (mine[i][j] == '.'){
        int count = 0;
        rep(k, 3){
          rep(l, 3){
            int a = i+dx[k], b = j+dy[l];
            
              if (a >= 0 && b >= 0 && a < h && b < w && mine[i+dx[k]][j+dy[l]] == '#'){
                count ++;
            }
          }
        }
        cout << count;
      }
      else{
        cout << '#';
      }
    } 
    cout << endl;
  }
  

}
