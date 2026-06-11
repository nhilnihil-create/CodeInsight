#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <numeric>
#include <regex>
#include <climits>

#define FOR(i, f, n) for(int (i) = (f), TMPend = (n); (i) < TMPend; (i)++)
#define RFOR(i, f, n) for(int (i) = (f), TMPend = (n); (i) >= TMPend; (i)--)
#define REP(i, n) for(int (i) = 0, TMPend = (n); (i) < TMPend; (i)++)
#define RREP(i, n) for(int (i) = (n); (i) >= 0; (i)--)
#define rep(i, n) for(int (i) = 0, TMPend = (n); (i) < TMPend; (i)++)
#define rrep(i, n) for(int (i) = (n); (i) >= 0; (i)--)
#define forin(i, a) for(auto i: (a))
#define p(...) printf(__VA_ARGS__); cout << endl;
#define in(...) __VA_ARGS__; input__(__VA_ARGS__);
#define input(...) in(__VA_ARGS__)
#define out(...) output__(__VA_ARGS__);
#define output(...) out(__VA_ARGS__)
#define list_input(x, n) x[(n)]; for(int (i) = 0; (i) < (n); (i)++) cin >> x[i];
#define lambda(a, b, c) [](auto const &a, auto const &b){ return c ;}
#define key(t, x, compare) [](const t &a, const t &b){ return a x compare b x ;}
#define unless(a) if(!(a))

using namespace std;

using pii = pair<int, int>;

template <class... T>
void input__(T &...a) {
  for(auto v: {&a...}) {
    cin >> *v;
  }
}

void output__(){
  cout << endl;
}

template <class Head, class... T>
void output__(Head const &v, T const &...a) {
  if(sizeof...(a) == 0) {
    cout << v;
  } else {
    cout << v << " ";
  }
  output__(a...);
}

int N;
vector<vector<long long>> A;

long long score(int state) {
  int t = 1;
  vector<int> hist;
  long long result = 0;
  rep(i, N) {
    if (state & t) {
      forin(h, hist) {
        result += A[i][h];
      }
      hist.push_back(i);
    }
    t <<= 1;
  }
  return result;
}

long long emp = numeric_limits<long long>::min();
vector<long long> dp(1 << 16);
long long dfs(int state) {
  if (dp[state] != emp) {
    return dp[state];
  }

  long long maxv = score(state);
  for (int t = (state - 1) & state; t > 0; t = (t - 1) & state) {
    maxv = max(maxv, dfs(state ^ t) + dfs(t));
  }
  return dp[state] = maxv;
}

int main(){

  int input(n);
  N = n;
  rep(i, n) {
    long long list_input(t, n);
    vector<long long> tmp(t, t + n);
    A.push_back(tmp);
  }

  fill(dp.begin(), dp.end(), emp);

  out(dfs((1 << n) - 1));
}
