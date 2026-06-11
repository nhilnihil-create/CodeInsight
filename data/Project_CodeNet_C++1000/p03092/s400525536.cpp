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

#ifndef LOCAL
#define debug(x) ;
#else
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << '{';
  for (const T &item : v) out << item << ", ";
  out << "\b\b}";
  return out;
}
#endif

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 5010

ll dp[SIZE][SIZE];

int main(){
  int N, A, B;
  int p[SIZE];

  cin >> N >> A >> B;

  for(int i=0;i<N;i++)
    cin >> p[i];

  for(int i=0;i<=N;i++)
    for(int j=0;j<=N;j++)
      dp[i][j] = LLINF * (i != 0);


  for(int i=0;i<N;i++){
    ll minVal = LLINF;

    for(int j=0;j<p[i];j++)
      minVal = min(minVal, dp[i][j]);

    for(int j=0;j<=N;j++){
      if(j < p[i]) dp[i+1][j] = dp[i][j] + A;
      if(j > p[i]) dp[i+1][j] = dp[i][j] + B;
    }

    dp[i+1][p[i]] = minVal;
  }

  ll ans = LLINF;

  for(int i=0;i<=N;i++)
    ans = min(ans, dp[N][i]);

  cout << ans << endl;

  return 0;
}
