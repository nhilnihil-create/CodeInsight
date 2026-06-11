#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

using namespace std;

typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int MAX_N = 200000;
int n;
i64 a[MAX_N];
i64 psum[MAX_N+1];

int main()
{
  cin >> n;
  psum[0] = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    psum[i+1] = psum[i] + a[i];
  }

  i64 m = LLONG_MAX;
  // i: 右端(含む)
  for (int i = 1; i < n-2; i++) {
    i64 t = psum[i+1];
    int j = upper_bound(psum, psum+i+2, t/2) - psum;
    pair<i64,i64> p1 = minmax(psum[j], t - psum[j]);
    if (j > 0) {
      pair<i64,i64> p2 = minmax(psum[j-1], t - psum[j-1]);
      if (p1.second - p1.first > p2.second - p2.first)
        p1 = p2;
    }
    //printf("p1={%ld, %ld}\n", p1.first, p1.second);

    i64 u = psum[i+1] + (psum[n] - psum[i+1]) / 2;
    int k = upper_bound(psum+i+2, psum+n+1, u) - psum;
    pair<i64,i64> p2 = minmax(psum[k] - psum[i+1], psum[n] - psum[k]);
    if (k > i+2) {
      pair<i64,i64> p3 = minmax(psum[k-1] - psum[i+1], psum[n] - psum[k-1]);
      if (p2.second - p2.first > p3.second - p3.first)
        p2 = p3;
    }
    //printf("p2={%ld, %ld}\n", p2.first, p2.second);
    //printf("i=%d j=%d k=%d\n", i, j, k);

    m = min(m, max(p1.second, p2.second) - min(p1.first, p2.first));
  }

  cout << m << endl;

  return 0;
}
