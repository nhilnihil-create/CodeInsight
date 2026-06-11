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
  int A, B, C; cin >> A >> B >> C;
  int K; cin >> K;
  priority_queue<int> que;
  que.push(A), que.push(B), que.push(C);
  for (int i = 0; i < K; ++i){
    int v = que.top() * 2; que.pop();
    que.push(v);
  }
  int ans = 0;
  while(!que.empty()) ans += que.top(), que.pop();
  cout << ans << endl;
}
