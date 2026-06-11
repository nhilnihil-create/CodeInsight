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
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
using lint = long long int;
using ll = long long int;
const lint INF = 1001001001001001LL;
const lint MOD = 1000000007LL;
int di[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dj[] = {0, 1, 0, -1, 1, 1, -1, -1};

void yes(){ cout << "yes" << endl; }
void Yes(){ cout << "Yes" << endl; }
void YES(){ cout << "YES" << endl; }
void no(){ cout << "no" << endl; }
void No(){ cout << "No" << endl; }
void NO(){ cout << "NO" << endl; }
void possible(){ cout << "possible" << endl; }
void Possible(){ cout << "Possible" << endl; }
void POSSIBLE(){ cout << "POSSIBLE" << endl; }
void impossible(){ cout << "impossible" << endl; }
void Impossible(){ cout << "Impossible" << endl; }
void IMPOSSIBLE(){ cout << "IMPOSSIBLE" << endl; }

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define srep(i,s,t) for(int i = s; i < t; i++)
#define all(a) a.begin(),a.end()

lint dp[2010][2];
lint a[2010];
lint n, z, w;

lint f(lint i, lint turn){
  if(dp[i][turn] != -1) return dp[i][turn];
  lint curVal = w;
  lint ret;
  if(i != 0) curVal = a[i - 1];
  
  if(turn == 0){
    // maximize
    ret = 0;
    srep(ni, i + 1, n){
      ret = max(ret, f(ni, 1));
    }
    ret = max(ret, (lint)abs(curVal - a[n - 1]));

  }else{
    // minimize
    ret = INF;
    srep(ni, i + 1, n){
      ret = min(ret, f(ni, 0));
    }
    ret = min(ret, (lint)abs(curVal - a[n - 1]));
  }

  dp[i][turn] = ret;
  return ret;
}

int main(){
  
  cin >> n >> z >> w;
  rep(i, n) cin >> a[i];
  rep(i, n + 1)
    rep(j, 2) dp[i][j] = -1;



  cout << f(0, 0) << endl; 
  return 0;
}
