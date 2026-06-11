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
  int x;
  cin >> x;
  int ans = 1;
  for(int i = 2; i*i<=x; ++i){
    int d = i;
    while(d<=x) d*=i;
    ans = max(ans,d/i);
  }
  cout << ans << endl;
}
