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
  int n,m,x,y;
  cin >> n >> m >> x >> y;
  int mx = x, my = y;
  rep(i,n){
    int xi;
    cin >> xi;
    mx = max(mx,xi);
  }
  rep(i,m){
    int yi;
    cin >> yi;
    my = min(my,yi);
  }
  cout << (mx<my?"No War":"War") << endl;
}
