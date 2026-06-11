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
  int n,h;
  cin >> n >> h;
  int a=1; priority_queue<int> b;
  rep(i,n){
    int x,y;
    cin >> x >> y;
    a = max(a,x);
    b.emplace(y);
  }
  int ans = 0;
  while(!b.empty()){
    int d = b.top(); b.pop();
    if(d<=a) break;
    h -= d;
    ++ans;
    if(h<=0) break;
  }
  if(h>0) ans += (h+a-1)/a;
  cout << ans << endl;
}