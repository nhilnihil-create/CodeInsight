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

ll d[3] = {3,5,7};
ll n;
int dfs(ll x=0) {
  if(x>n) return 0;

  int res = 0;
  rep(i,3) res += dfs(x*10+d[i]);
  set<int> s;
  while(x>0){
    s.emplace(x%10);
    x /= 10;
  }
  if(s.size()==3) ++res;
  return res;
}
int main() {
  cin >> n;
  cout << dfs() << endl;
}
