#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int_Max 2147483647
#define ll_Max 9223372036854775807
#define REP(i,f,n) for(int i=f; i<(n); i++)
int xh[8] ={ 1,-1, 1,-1, 1,-1, 0, 0};
int yh[8] ={ 1,-1,-1, 1, 0, 0, 1,-1};

int main()
{
  int h, w;
  cin >> h >> w;
  string s[h];
  REP(i,0,h){
    cin >> s[i];
  }
  REP(i,0,h){
    REP(j,0,w){
      int cnt = 0;
      if(s[i][j] == '.'){
        REP(k,0,8){
          int x = j + xh[k], y = i + yh[k];
          if(x < 0 || w <= x)continue;
          if(y < 0 || h <= y)continue;
          if(s[y][x] == '#')cnt++;
        }
        cout << cnt;
      }else{
        cout << "#";
      }
    }
    cout << endl;
  }

  //--debug : end_stoper
  //string end_stoper; cin >> end_stoper;

  return 0;
}