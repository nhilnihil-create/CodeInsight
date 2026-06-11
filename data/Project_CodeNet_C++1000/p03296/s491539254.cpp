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
#include <bitset>

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
  vector<int> a(N); rep(i, N) cin >> a[i];
  vector<int> que;
  for (int i = 0; i < N; ++i){
    int length = 1;
    while (a[i] == a[i + 1] && i + 1 < N) i++, length++;
    que.emplace_back(length);
  }
  ll ans = 0;
  rep(i, que.size()){
    ans += que[i] / 2;
  }
  cout << ans << endl;
}
