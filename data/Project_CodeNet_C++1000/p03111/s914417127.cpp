#include <bits/stdc++.h>
using namespace std;
#define FOR(i, o, n) for (auto i = (o); (i) < (n); ++(i))
#define FOR1(i, n) FOR(i, 1, n+1)
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (auto i = (n)-1; (i) >= 0; --i)
#define REPI(itr, v) for (auto itr = v.begin(); itr != v.end(); ++itr)
#define REPIR(itr, v) for (auto itr = v.rbegin(); itr != v.rend(); ++itr)
#define fi first
#define se second
#define ll long long
#define int long long
#define V2(name, h, w) vector<vector<int> > name((h), vector<int>(w));

#define dl(line) cerr << "RUN: until " << (line) << "th line." << endl
#define dv(name, value) cerr << (name) << " is " << (value) << endl
#define da(v)  cerr << "["; REPI(itr, v){cerr << *itr << (itr != --v.end() ? ", " : "");} cerr << "]" << endl

int N, A, B, C;
std::vector<long long> l(9);

int dfs(int current, int a, int b, int c) {
  if (N == current) {
    if (min(a,min(b, c)) > 0) {
      return abs(A - a) + abs(B - b) + abs(C - c) - 30;
    } else {
      return INT_MAX;
    }
  }

  int ret1 = dfs(current + 1, a, b, c);
  int ret2 = dfs(current + 1, a + l.at(current), b, c) + 10;
  int ret3 = dfs(current + 1, a, b + l.at(current), c) + 10;
  int ret4 = dfs(current + 1, a, b, c + l.at(current)) + 10;

  // dv("ret1", ret1);
  // dv("ret2", ret2);
  // dv("ret3", ret3);
  // dv("ret4", ret4);
  // dv("min", min(min(ret1, ret2), min(ret3, ret4)));
  return min(min(ret1, ret2), min(ret3, ret4));
}

signed main(){
  scanf("%lld",&N);
  scanf("%lld",&A);
  scanf("%lld",&B);
  scanf("%lld",&C);
  for(int i = 0 ; i < N ; i++){
    scanf("%lld",&l[i]);
  }
  cout << dfs(0,0,0,0) << endl;
}
