#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int c[3][3];
  rep(i,3)rep(j,3) cin >> c[i][j];

  bool ok = true;
  int d1 = c[2][1]-c[2][0], d2 = c[2][2]-c[2][1];
  rep(i,2){
    if(c[i][1]-c[i][0]!=d1) ok = false;
    if(c[i][2]-c[i][1]!=d2) ok = false;
  }
  d1 = c[1][2]-c[0][2], d2 = c[2][2]-c[1][2];
  rep(j,2){
    if(c[1][j]-c[0][j]!=d1) ok = false;
    if(c[2][j]-c[1][j]!=d2) ok = false;
  }
  cout << (ok?"Yes":"No") << endl;
}
