#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { std::cout << #a << " = " << a << "\n"; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }
template<class T, class V> istream& operator>> (istream& ist, pair<T, V>& p) { return ist >> p.first >> p.second; }
template<class T> ostream& operator<< (ostream& ost, pair<T, T>& p) { return ost << p.first << ", " << p.second; }
template<class T> istream& operator>> (istream& ist, vector<T>& vs) { for(auto& e: vs) ist >> e; return ist; }

typedef long long ll;
int const inf = INT_MAX / 2;

int main() {
  int N; cin >> N;
  vector<int> vs(N); cin >> vs;
  map<int, int> m1, m2;
  rep(i, N / 2) {
    m1[vs[2 * i]]++;
    m2[vs[2 * i + 1]]++;
  }
  vector<pair<int, int>> v1, v2;
  for(auto e: m1) v1.emplace_back(e.second, e.first);
  for(auto e: m2) v2.emplace_back(e.second, e.first);
  sort(v1.rbegin(), v1.rend());
  sort(v2.rbegin(), v2.rend());

  vector<pair<int, int>> w1, w2;
  rep(i, min(2, (int)v1.size())) w1.emplace_back(v1[i].second, v1[i].first);
  rep(i, min(2, (int)v2.size())) w2.emplace_back(v2[i].second, v2[i].first);

  int ans = inf;
  for (auto e: w1) for (auto f: w2) {
    if (e.first == f.first) {
      ans = min(ans, N - max(e.second, f.second));
    }
    else {
      ans = min(ans, N - e.second - f.second);
    }
  }

  cout << ans << endl;
}
