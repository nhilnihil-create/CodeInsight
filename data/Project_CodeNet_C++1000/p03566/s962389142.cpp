#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(){
  int N;
  cin >> N;
  vector<int> t(N), v(N+1);
  rep(i, N) {
    cin >> t[i];
    if(i)
      t[i] += t[i-1];
  }
  rep(i, N) cin >> v[i];
  vector<double> graph(t[N-1]*2+1);
  int p = 0;
  rep(i, t[N-1]*2+1) {
    while(i/2.0 > t[p]) p++;
    double mn = i/2.0;
    rep(j, p)
      chmin(mn, v[j]+i/2.0-t[j]);
    chmin(mn, (double)v[p]);
    for(int j=p; j<N; j++)
      chmin(mn, v[j+1]+t[j]-i/2.0);
    graph[i] = mn;
  }
  double ans = 0;
  rep(i, t[N-1]*2)
    ans += (graph[i]+graph[i+1])*0.5/2;
  cout << fixed << setprecision(3) << ans << endl;
  return 0;
}