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
  vector<int> A(N), B(N);
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];
  vector<int> surpluses;
  ll deficit_sum = 0;
  int deficit_count = 0;
  rep(i, N) {
    if (A[i] - B[i] > 0) {
      surpluses.push_back(A[i] - B[i]);
    }
    if (A[i] - B[i] < 0) {
      deficit_count++;
      deficit_sum += B[i] - A[i];
    }
  }
  sort(surpluses.begin(), surpluses.end());
  int size = surpluses.size();
  int used_count = 0;
  rep(i, size) {
    if (deficit_sum > 0) {
      deficit_sum -= surpluses[size - 1 - i];
      used_count++;
    }
  }
  cout << (deficit_sum > 0 ? -1 : deficit_count + used_count) << "\n";
}
