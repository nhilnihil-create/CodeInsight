#pragma region
#include <bits/stdc++.h>
using namespace std;
inline void ci(void){
  return;
}
template <typename First, typename... Rest>
void ci(First& first, Rest&... rest){
  cin >> first;
  ci(rest...);
  return;
}
inline void co(void){
  cout << endl;
  return;
}
template <typename First, typename... Rest>
void co(First first, Rest... rest){
  cout << first << "";
  co(rest...);
  return;
}
#define ll long long
#define ld long double
#define st string
#define dl double
#define wh while
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define tp tuple
#define ft first
#define sc second
#define ve vector
#define tos to_string
#define len length
#define rt return
#define br break
#define con continue
#define lcm(n, m) (n * m / gcd(n, m))
#define np next_permutation
#define repi(i, m, n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i, n) repi(i, 0, n)
#define repill(i, m, n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define repll(i, n) repill(i, 0, n)
#define revi(i, m, n) for(int i=(int)(m);i>(int)(n);i--)
#define rev(i, m) revi(i, m, 0)
#define revill(i, m, n) for(ll i=(ll)(m);i>(ll)(n);i--)
#define revll(i, n) revill(i, 0, n)
#define sz(v) ((int)(v).size()) 
#define each(i, n) for(auto&& i: n)
#define all(n) (n.begin(), n.end())
#define allr(n) (n.rbegin(), n.rend())
#define sp(n) cout << fixed << setprecision(n)
#define inf pow(10, 9)
#pragma endregion
// sqrt ルート, int 2*10^9, gcd　最大公約数
// __builtin_popcount bitの個数

int main() {
  int H, W;
  ci(H, W);
  ve<ve<char>> A(H, ve<char>(W));
  queue<pair<int, int>> Q;
  ve<ve<int>> n(H, ve<int>(W, inf));
  ve<pair<int, int>> C;
  rep(i, H){
    rep(j, W){
      ci(A.at(i).at(j));
      if(A.at(i).at(j) == '#'){
        Q.push(mp(i, j));
        n.at(i).at(j) = 0;
      }
    }
  }
  ve<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
  wh(sz(Q)){
    int x = Q.front().ft, y = Q.front().sc;
    Q.pop();
    rep(j, 4){
      int ax = x + dx.at(j), ay = y + dy.at(j);
      if(ax < 0 || H <= ax || ay < 0 || W <= ay){
        con;
      }
      if(n.at(ax).at(ay) != inf){
        con;
      }
      if(A.at(ax).at(ay) != '#'){
        Q.push(mp(ax, ay));
        n.at(ax).at(ay) = n.at(x).at(y) + 1;
      }
    }
  }
  int a = 0;
  rep(i, H){
    rep(j, W){
      a = max(a, n.at(i).at(j));
    }
  }
  co(a);
}
