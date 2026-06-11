#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int N, H;
  cin >> N >> H;
  vector<int> a(N), b(N);
  for (int i=0; i<N; i++) cin >> a[i] >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  reverse(b.begin(), b.end());
  int res = 0;
  for (int i=0; i<N; i++) {
    if (H>0&&b[i]>=a[N-1]) {
      H -= b[i];
      res++;
    }
    else if (H<=0) {
      cout << res << endl;
      return 0;
    }
    else if (b[i]<a[N-1]) break;
  }
  if (H<=0) cout << res << endl;
  else {
    if (H%a[N-1]==0) res += H/a[N-1];
    else res += H/a[N-1]+1;
    cout << res << endl;
  }
  return 0;
}