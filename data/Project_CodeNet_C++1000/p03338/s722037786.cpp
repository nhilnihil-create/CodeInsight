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
  int n; string s;
  cin >> n >> s;
  
  vector<int> l(26),r(26);
  rep(i,n) r[s[i]-'a']++;
  int ans = 0;
  for(int i=0; i<n-1; ++i){
    r[s[i]-'a']--;
    l[s[i]-'a']++;
    int res = 0;
    rep(c,26) if(l[c]>0&&r[c]>0) ++res;
    ans = max(ans,res);
  }
  cout << ans << endl;
}
