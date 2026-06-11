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

const int MAX_N = 2000;
int n, k, q;
int a[MAX_N];
int b[MAX_N];
int c[MAX_N];

int main()
{
  cin >> n >> k >> q;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int m = INT_MAX;
  for (int i = 0; i < n; i++) {
    int ai = 0, ci = 0;
    while (ai < n) {
      int bi = 0;
      while (ai < n && a[i] <= a[ai]) {
        b[bi++] = a[ai++];
      }
      ai++;
      sort(b,b+bi);
      for (int l = 0; l < bi - k + 1; l++) {
        c[ci++] = b[l];
      }
    }
    if (ci >= q) {
      sort(c,c+ci);
      m = min(m, c[q-1] - c[0]);
    }
  }
  cout << m << endl;

  return 0;
}
