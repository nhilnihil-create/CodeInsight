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

int a[505][505];
int main() {
  int h,w;
  cin >> h >> w;
  rep(i,h)rep(j,w) cin >> a[i][j];

  vector<tuple<int,int,int,int>> ans;
  rep(i,h)rep(j,w-1){
    if(a[i][j]%2==1) {
      a[i][j]--; a[i][j+1]++;
      ans.emplace_back(i,j,i,j+1);
    }
  }
  int j = w-1;
  rep(i,h-1){
    if(a[i][j]%2==1) {
      a[i][j]--; a[i+1][j]++;
      ans.emplace_back(i,j,i+1,j);
    }
  }
  cout << ans.size() << endl;
  rep(i,ans.size()){
    int a,b,c,d;
    tie(a,b,c,d) = ans[i];
    ++a;++b;++c;++d;
    printf("%d %d %d %d\n",a,b,c,d);
  }
}