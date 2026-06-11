#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()

int N;
vector<i64> A;

vector<i64> sum;

int main() {
  cin >> N;
  A.resize(N + 1);
  sum.resize(N + 1);
  rep(i,1,N) cin >> A[i];
  rep(i,1,N) sum[i] = sum[i - 1] + A[i];

  i64 ans = 1e18;

  rep(i,2,N - 2) {
    {
      int j = lower_bound(begin(sum) + 1, end(sum), sum[i] / 2) - begin(sum);
      int k = lower_bound(begin(sum) + 1, end(sum), (sum[N] + sum[i]) / 2) - begin(sum);
      for(int cc = max(0, j - 1);cc <= min(i - 1, j + 1);cc++) {
        for(int dd = max(i + 1, k - 1);dd <= min(N, k + 1);dd++) {
          vector<i64> vec = { sum[cc], sum[i] - sum[cc], sum[dd] - sum[i], sum[N] - sum[dd] };
          sort(all(vec));
          ans = min(ans , vec.back() - vec.front());
        }
      }
    }
  }

  cout << ans << endl;
}
