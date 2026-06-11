#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
using lint = long long int;
long long int INF = 1001001001001001LL;
int inf = 1000000007;
long long int MOD = 1000000007LL;
double PI = 3.1415926535897932;

template<typename T1,typename T2>inline void chmin(T1 &a,const T2 &b){if(a>b) a=b;}
template<typename T1,typename T2>inline void chmax(T1 &a,const T2 &b){if(a<b) a=b;}

#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()

/* do your best */
int imos[35][200010] = {};

int main(){
  
  int n, c; cin >> n >> c;

  for (int i = 0; i < n; i++) {
    int s, t, c; cin >> s >> t >> c;
    c--;
    imos[c][2 * s - 1]++;
    imos[c][2 * t]--;
  } 

  for (int i = 0; i < c; i++) {
    for (int j = 1; j < 200010; j++) {
      imos[i][j] += imos[i][j - 1];
    }
  }

  int ans = 0;
  for (int i = 0; i < 200010; i++) {
    int tmp = 0;
    for (int k = 0; k < c; k++) {
      if (imos[k][i]) tmp++;
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;

  return 0;
}
