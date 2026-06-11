#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> cnt(3);
  REP(i, n) cnt[s[i] - 'a']++;
  sort(ALL(cnt));
  cout << (cnt[2] - cnt[0] <= 1 ? "YES" : "NO") << endl;
  return 0;
}