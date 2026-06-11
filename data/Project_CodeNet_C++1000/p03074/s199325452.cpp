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
  int N, K; cin >> N >> K;
  string S; cin >> S;

  vector<int> que;
  int n_zero = 0, n_one = 0;
  if (S[0] != '1') que.push_back(0);
  rep(i, N){
    if (S[i] == '0'){
      if (n_one != 0) que.push_back(n_one);
      n_zero++;
      n_one = 0;
    }
    else{
      if (n_zero != 0) que.push_back(n_zero);
      n_one++;
      n_zero = 0;
    }
    if (i == N - 1){
      if (S[i] == '0') que.push_back(n_zero);
      else que.push_back(n_one);
    }
  }
  vector<int> s((int)que.size() + 1, 0);
  rep(i, (int)que.size()) s[i + 1] = s[i] + que[i];
  int ans = 0;
  for (int left = 0; left < s.size(); left += 2){
    int right = left + K * 2 + 1;
    if (right >= s.size()) right = (int)s.size() - 1;
    ans = max(ans, s[right] - s[left]);
  }
  cout << ans << endl;
  /*
  rep(i, (int)que.size()) cout << que[i] << " ";
  cout << endl;
  rep(i, (int)s.size()) cout << s[i] << " ";
  cout << endl;*/

}
