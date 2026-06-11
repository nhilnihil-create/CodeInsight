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
  int n = 5;
  vector<int> que(n);
  rep(i, n) cin >> que[i];

  vector<int> index(n);
  rep(i, n) index[i] = i;
  int ans = INF;
  do{
    int time = 0;
    rep(i, n){
      time += que[index[i]];
      if (time % 10 != 0 && i != n - 1) time = (time / 10 + 1) * 10;
    }
    ans = min(ans, time);
  }while (next_permutation(index.begin(), index.end()));
  cout << ans << endl;
}
