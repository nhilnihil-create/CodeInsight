#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  unordered_map<int, int> mp{};
  REP(i, N) {
    cin >> a[i];
    mp[a[i]]++;
  }
  ll ans = 0;
  for (auto s : mp) {
    if(s.first<=s.second){
      ans += s.second - s.first;
    }else{
      ans += s.second;
    }
  }
  cout << ans << endl;
}