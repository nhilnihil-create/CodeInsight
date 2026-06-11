#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, int> PL;
constexpr int mod = 1e9 + 7;
constexpr int INF = 2e9;

int main() {
  ll n;
  cin >> n;
  int res = 0;

  auto dfs = [&](auto& f, ll now, int s)->void{
    if (now > n) return ;
    if (s == 7) res++;
    f(f, now * 10 + 3, s | (1 << 0));
    f(f, now * 10 + 5, s | (1 << 1));
    f(f, now * 10 + 7, s | (1 << 2));
  };

  dfs(dfs, 0, 0);
  cout << res << endl;
  return 0;
} 