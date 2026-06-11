#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <cmath>

#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
using P = pair<ll, ll>;

template<class T> inline bool chmin(T& a,T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if (a < b) {a = b; return true;} return false;}

const ll MOD = 1000000007;
const int INF = 1<<30;
//const ll INF = (ll)1e18 + 1;

int main(){
  int N; cin >> N;
  vector<ll> a(N); rep(i, N) cin >> a[i];
  int n_minus = 0;
  rep(i, N) if (a[i] < 0) n_minus++;
  ll sum = 0;
  rep(i, N) {
    a[i] = abs(a[i]);
    sum += a[i];
  }
  if (n_minus % 2 == 0) cout << sum << endl;
  else {
    ll min_num = INF;
    rep(i, N){
      min_num = min(min_num, a[i]);
    }
    sum -= 2 * min_num;
    cout << sum << endl;
  }
}
