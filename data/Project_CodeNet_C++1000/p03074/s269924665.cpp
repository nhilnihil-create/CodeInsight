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
  int N, K; cin >> N >> K;
  string S; cin >> S;
  vector<pair<int, int>> vs;
  for (int end = 0; end < N;) {
    int start = end;
    while (end < N && S[end] == S[start]) end++;
    vs.emplace_back(S[start] - '0', end - start);
  }

  int left = 0, right = 0, cnt = 0, curr = 0, ans = 0;
  while (left <= right) {
    if (right < vs.size() && vs[right].first == 0 && cnt < K) {
      cnt++;
      curr += vs[right++].second;
      ans = max(ans, curr);
    }
    else if (right < vs.size() && vs[right].first == 1) {
      curr += vs[right++].second;
      ans = max(ans, curr);
    }
    else if (cnt == K) {
      if (left < N && vs[left].first == 1) {
        curr -= vs[left++].second;
      }
      curr -= vs[left++].second;
      cnt--;
    }
    else {
      break;
    }
  }
  cout << ans << endl;
}
