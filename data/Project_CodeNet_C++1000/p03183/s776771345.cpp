#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#ifdef LOCAL
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;
#else
#define debug(x) ;
#endif

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 3010
#define SIZE2 20010

ll dp[SIZE2];

int main(){
  int n, w[SIZE], s[SIZE], v[SIZE];
  pair<int,int> blocks[SIZE];

  scanf("%d", &n);

  for(int i=0;i<n;i++){
    scanf("%d%d%d", w+i, s+i, v+i);
    blocks[i] = {s[i]+w[i], i};
  }

  sort(blocks, blocks+n);

  for(int i=1;i<SIZE2;i++){
    dp[i] = -LLINF;
  }

  ll ans = 0;

  for(int i=0;i<n;i++){
    int id = blocks[i].second;

    for(int j=s[id];j>=0;j--){
      dp[j+w[id]] = max(dp[j+w[id]], dp[j] + v[id]);
      ans = max(ans, dp[j+w[id]]);
    }
  }

  cout << ans << endl;

  return 0;
}
