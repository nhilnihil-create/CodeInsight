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
  if(n==0){
    cout << 0 << endl;
    return 0;
  }
  vector<int> ans;
  int d = 1;
  if(n<0){
    n=-n; d=-d;
  }
  while(n>0){
    if(n&1){
      ans.push_back(1);
      n -= d;
    }else{
      ans.push_back(0);
    }
    n>>=1;
    d=-d;
  }
  rep(i,ans.size()) cout << ans[ans.size()-1-i];
  cout << endl;
}
