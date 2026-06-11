#include <bits/stdc++.h>
#define REP(i, n) for (long i = 0; i < n; ++i)

using namespace std;
using ll = long long;
using P = pair<long, long>;

void solve(long N, long H, vector<long> a, vector<long> b) {

  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());

  long count(0);
  // throw Bs
  while (H > 0 && b.size() && b.front() > a.front()) {
    H -= b.front();
    b.erase(b.begin());
    count++;
  }
  // swing A
  if (H > 0)
    count += ceil(H * 1.0 / a.front());

  cout << count << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  long N, H;
  cin >> N >> H;

  vector<long> a(N);
  vector<long> b(N);
  REP(i, N)
    cin >> a[i] >> b[i];

  solve(N, H, move(a), move(b));

  return 0;
}
