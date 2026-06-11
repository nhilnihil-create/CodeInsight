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

int c[10][10];
int main() {
  int h,w;
  cin >> h >> w;
  rep(i,10)rep(j,10) cin >> c[i][j];
  rep(k,10)rep(i,10)rep(j,10) if(c[i][j]>c[i][k]+c[k][j]) c[i][j] = c[i][k]+c[k][j];
  int ans = 0;
  rep(i,h*w){
    int a;
    cin >> a;
    if(a!=-1) ans += c[a][1];
  }
  cout << ans << endl;
}