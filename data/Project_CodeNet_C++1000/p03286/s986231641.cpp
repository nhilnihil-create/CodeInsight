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

P division_code(double a, double b){
  P res;
  if (b < 0) {
    res.first = ceil(a / b);
    res.second = a - b * res.first;
  }
  else {
    res.first = floor(a / b);
    res.second = a - b * res.first;
  }
  return res;
}

int main(){
  int N; cin >> N;
  P res;
  string ans;
  while (true){
    res = division_code(N, -2);
    ans += to_string(res.second);
    N = res.first;
    if (res.first == 0) break;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}
