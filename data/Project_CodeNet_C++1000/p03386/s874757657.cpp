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
  int a,b,k;
  cin >> a >> b >> k;
  vector<int> ans;
  if(b-a+1<k*2){
    rep(i,b-a+1) ans.emplace_back(a+i);
  }else{
    rep(i,k) ans.emplace_back(a+i);
    rep(i,k) ans.emplace_back(b-k+1+i);
  }
  rep(i,ans.size()) printf("%d\n",ans[i]);
}
