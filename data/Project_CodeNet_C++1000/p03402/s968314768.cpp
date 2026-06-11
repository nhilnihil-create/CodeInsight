#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mod 1000000007
using ll = long long;
using namespace std;
int main(){
  int a,b;
  cin >> a >> b;
  a--;
  b--;
  vvi color(100, vi(100,0)); //0:black, 1: white
  for(int y = 50; y < 100; y++){
    rep(x, 100) color[y][x] = 1;
  }
  cout << "100 100" << endl;
  rep(y, 50){
    if(y % 2 == 0){
      for(int x = 0; x < 100; x++){
        if(a && x % 2 == 0){
          cout << '.';
          a--;
        }else cout << '#';
      }
    }else{
      rep(x, 100)
      cout << '#';
    }
    cout << endl;
  }
  for(int y = 99; y >= 50; y--){
    if(y % 2 == 0){
      for(int x = 0; x < 100; x += 2){
        if(b){
          //cout << '#';
          color[y][x] = 0;
          b--;
        }//else cout << '.';
      }
    }else{
      
    }
  }
  for(int y = 50; y < 100; y++){
    rep(x, 100){
      if(!color[y][x]) cout << '#';
      else cout << '.';
    }
    cout << endl;
  }
}