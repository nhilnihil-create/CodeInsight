// includes
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <climits>
#include <bitset>
#include <list>

// macros
#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for(int i=((int)(n)-1);i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())

using namespace std;

//  types
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
typedef pair<double, double> Pd;
 
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;
const int mod = 1e9 + 7;

// solve
template <class T>bool chmax(T &a, const T &b){if(a < b){a = b; return 1;} return 0;}
template <class T>bool chmin(T &a, const T &b){if(a > b){a = b; return 1;} return 0;}

ll dp[1001][20001];
struct block{
  int w;
  int s;
  ll v;
};

bool comp(const block &x, const block &y){
  return x.s + x.w < y.s + y.w;
}

int main(int argc, char const* argv[])
{
  int n;
  cin >> n;
  vector<block> b(n);
  rep(i, n)cin >> b[i].w >> b[i].s >> b[i].v;
  sort(all(b), comp);
  rep(i, n){
    rep(j, b[i].w + b[i].s + 1){
      dp[i+1][j] = dp[i][j];
      if(0 <= j - b[i].w && j - b[i].w <= b[i].s)chmax(dp[i+1][j], dp[i][j-b[i].w] + b[i].v);
    }
  }
  ll res = 0;
  rep(i, b[n-1].w + b[n-1].s + 1){
    chmax(res, dp[n][i]);
  }
  cout << res << endl;
	return 0;
}
