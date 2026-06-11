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
  int N, M, X, Y; cin >> N >> M >> X >> Y;
  vector<int> x(N), y(M);
  rep(i, N) cin >> x[i];
  rep(i, M) cin >> y[i];
  x.push_back(X);
  y.push_back(Y);
  sort(x.begin(), x.end(), greater<int>());
  sort(y.begin(), y.end(), less<int>());
  if (y[0] - x[0] >= 1) cout << "No War" << endl;
  else cout << "War" << endl;
}
