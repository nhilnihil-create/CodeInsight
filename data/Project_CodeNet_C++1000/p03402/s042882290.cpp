#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}


int main(){
  int w,b;
  cin >> w >> b;
  w--;
  b--;
  cout << 100 << ' ' << 100 << endl;

  string whiteBoard = "", blackBoard="";
  rep(i,50){
    whiteBoard += ".";
    blackBoard += "#";
  }

  string dotBlackBoard,dotWhiteBoard;
  rep(i,100){
    if(i % 2 == 1){
      dotBlackBoard = whiteBoard;
      dotWhiteBoard = blackBoard;

      rep(j,20){
        if(j % 2 == 0) continue;
        else if(b > 0) {
          dotBlackBoard[j] = '#';
          b--;
        }
      }
      rep(j,20){
        if(j % 2 == 0) continue;
        else if(w > 0) {
          dotWhiteBoard[j] = '.';
          w--;
        }
      }
      cout << dotBlackBoard << dotWhiteBoard << endl;
    }else{
      cout << whiteBoard << blackBoard << endl;
    }
  }

  return 0;
}
