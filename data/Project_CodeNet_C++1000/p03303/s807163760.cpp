#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,a) for(auto &i:a)
#define all(a) (a).begin(),(a).end()
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
using ll = long long; constexpr int inf = INT_MAX / 2; constexpr ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

void _main() {
  string S;
  int w;
  cin >> S >> w;

  string ans;
  for (int i=0; i<(int)S.size(); i+=w) ans.push_back(S[i]);

  cout << ans << endl;
}