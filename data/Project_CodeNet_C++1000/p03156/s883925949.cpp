#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
#define ALL(v) v.begin(), v.end()
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define chmax(x, a) x = max(x, a)
#define chmin(x, a) x = min(x, a)

int main() {
  int N; cin >> N;
  int A, B; cin >> A >> B;
  vector<int> P(N);
  rep(i, N) cin >> P[i];
  sort(ALL(P));
  vector<int> vec(3);
  rep(i, N) {
    if (P[i] <= A) vec[0]++;
    else if (P[i] > B) vec[2]++;
    else vec[1]++;
  }
  cout << vmin(vec) << endl;
}
