#ifdef __APPLE__
#include "bits:stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;
auto scan = []{ static LL a; scanf("%lld", &a); return a;};


string s, noxs;
LL toid(char c){
  return c - 'a';
}
LL dp[300000] = {0};
int main() {
  cin >> s;
  map<LL,LL> mx;
  mx[0] = -1;
  LL cur = 0, n = s.size();
  for(LL i = 0; i < n; ++i){
    cur ^= 1ll << toid(s[i]);
    dp[i] = i == 0? 1: dp[i - 1] + 1;
    if (mx.count(cur) ){
      if (mx[cur] == -1) dp[i] = 1;
      else dp[i] = min(dp[i], dp[mx[cur]] + 1);
    }
    for(LL j = 0; j < 26 ; ++j) {
      LL targ = cur ^ (1ll<<j);
      if (mx.count(targ) ){
        if (mx[targ] == -1) dp[i] = 1;
        else dp[i] = min(dp[i], dp[mx[targ]] + 1);
      }
    }
    
    if(!mx.count(cur)) mx[cur] = i;
    else if(mx[cur] == -1) dp[i] = 1;
    else {
      mx[cur] = dp[mx[cur]] < dp[i] ? mx[cur] : i;
    }
  }
  //if(__builtin_popcountll(cur)<=1)return 0 * puts("1");
  printf("%lld\n",dp[n - 1]);
}




/*
 4
 3
 0 0
 1 1
 1 2
 3
 1 2
 2 4
 4 8
 4
 1 1
 2 2
 3 3
 4 4
 5
 0 0
 2 0
 0 2
 2 2
 1 1
 
 */
