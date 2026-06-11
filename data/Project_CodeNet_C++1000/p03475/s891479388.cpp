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
  vector<int> c(N - 1), s(N - 1), f(N - 1);
  rep(i, N - 1) cin >> c[i] >> s[i] >> f[i];

  for (int i = 0; i < N - 1; ++i){
    int now = s[i] + c[i];
    for (int j = i + 1; j < N - 1; ++j){
      if (now >= s[j]){
        if (now % f[j] != 0) now += (f[j] - now % f[j]);
      }
      else now = s[j];
      now += c[j];
    }
    cout << now << endl;
  }
  cout << 0 << endl;
}
