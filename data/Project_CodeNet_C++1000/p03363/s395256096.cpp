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
  vector<int> A(N); cin >> A;
  vector<ll> S(N + 1);
  rep(i, N) {
    S[i + 1] = S[i] + A[i];
  }
  map<ll, int> mp;
  rep(i, N + 1) mp[S[i]]++;
  ll ans = 0;
  for(auto e: mp) {
    ans += (ll)e.second * (e.second - 1) / 2;
  }
  cout << ans << "\n";
}
