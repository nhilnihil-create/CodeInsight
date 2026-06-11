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
  cout << "\n";
  return;
}
template <typename First, typename... Rest>
void co(First first, Rest... rest){
  cout << first << " ";
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
#define rt return 0
#define br break
#define gcd __gcd
#define lcm(n, m) (n * m / gcd(n, m))
#define np next_permutation
#define repi(i, m, n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i, n) repi(i, 0, n)
#define revi(i, m, n) for(int i=(int)(m);i>(int)(n);i--)
#define rev(i, n) repi(i, 0, n)
#define repill(i, m, n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define repll(i, n) repill(i, 0, n)
#define revill(i, m, n) for(ll i=(ll)(m);i>(ll)(n);i--)
#define revll(i, n) repi(i, 0, n)
#define sz(v) ((int)(v).size()) 
#define each(i, n) for(auto&& i: n)
#define all(n) (n.begin(), n.end())
#define sp(n) cout << fixed << setprecision(n)
#pragma endregion
// sqrt ルート, int 2*10^9, gcd　最大公約数
// ve<ve<要素の型>> 変数名(縦, ve<要素の型>(横, 初期値))

int main() {
  ld N, a = 0;
  ci(N);
  rep(i, N){
    ld x;
    st y;
    ci(x, y);
    if(y == "JPY"){
      a += x;
    }
    else{
      a += x * 380000;
    }
  }
  sp(10);
  co(a);
}