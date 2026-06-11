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
  int n;
  cin >> n;
  map<int,int> m;
  rep(i,n){
    int a;
    cin >> a;
    m[a]++;
  }
  int ans = 0;
  for(auto i:m){
    if(i.first>i.second) ans += i.second;
    else ans += i.second-i.first;
  }
  cout << ans << endl;
}
