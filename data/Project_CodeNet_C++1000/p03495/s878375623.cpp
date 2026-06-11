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
  int n,k;
  cin >> n >> k;
  map<int,int> m;
  rep(i,n){
    int a;
    cin >> a;
    m[a]++;
  }
  priority_queue<int,vector<int>,greater<int>> q;
  for(auto i:m) q.emplace(i.second);
  int ans = 0;
  while(q.size()>k){
    ans += q.top(); q.pop();
  }
  cout << ans << endl;
}
