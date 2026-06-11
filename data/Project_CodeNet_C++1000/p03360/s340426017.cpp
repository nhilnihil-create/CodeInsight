#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000000LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
  int n[3], k;
  rep(i, 3) cin >> n[i];
  cin >> k;
  int index;
  if(n[0] >= n[1] && n[0] >= n[2]) index = 0;
  if(n[1] >= n[0] && n[1] >= n[2]) index = 1;
  else index = 2;


  rep(i, k)
  n[index] *= 2;

  cout << n[0] + n[1] + n[2] << ln;
}
  
