#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long ll;

int dpx[8000][20000];
int dpy[8000][20000];
  
int main()
{
  string s;
  int x, y;
  cin >> s >> x >> y;
  s += "T";

  int nx = 0, ny = 0;
  int xx[8000], yy[8000];
  int c = 0, n = 0;
  for(int i = 0; i < s.length(); i++){
    if(s[i] == 'T'){
      if(n == 0) x -= c;
      else if(c){
        if(n % 2 == 0) xx[nx++] = c;
        else yy[ny++] = c;
      }
      c = 0;
      n++;
    }else{
      c++;
    }
  }

  dpx[0][10000] = 1;
  for(int i = 0; i < nx; i++){
    for(int j = 0; j < 20000; j++){
      if(dpx[i][j]){
        dpx[i+1][j+xx[i]] = 1;
        dpx[i+1][j-xx[i]] = 1;
      }
    }
  }

  dpy[0][10000] = 1;
  for(int i = 0; i < ny; i++){
    for(int j = 0; j < 20000; j++){
      if(dpy[i][j]){
        dpy[i+1][j+yy[i]] = 1;
        dpy[i+1][j-yy[i]] = 1;
      }
    }
  }

  if(dpx[nx][x+10000] && dpy[ny][y+10000]){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

  return 0;
}
