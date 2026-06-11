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
  string S; cin >> S;
  string T; cin >> T;
  int n = S.length();

  vector<int> s(26), t(26);
  rep(i, n){
    s[S[i] - 'a']++;
    t[T[i] - 'a']++;
  }
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  rep(i, 26){
    if (s[i] != t[i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
