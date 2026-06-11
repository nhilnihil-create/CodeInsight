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

const int MAX_N = 100000;
int n;
int a[MAX_N];
int b[MAX_N];

i64 ceil_div(i64 a, i64 b)
{
  return a / b + (a % b != 0 ? 1 : 0);
}

i64 count_inv(vi &a)
{
  int n = a.size();
  if (n <= 1) return 0;

  vi b(a.begin(), a.begin()+n/2);
  vi c(a.begin()+n/2, a.end());

  i64 r = count_inv(b) + count_inv(c);

  int bi = 0, ci = 0;
  for (int ai = 0; ai < n; ai++) {
    if (bi < (int)b.size() && (ci == (int)c.size() || b[bi] <= c[ci])) {
      a[ai] = b[bi++];
    } else {
      a[ai] = c[ci++];
      r += bi;
    }
  }

  return r;
}

bool f(int x)
{
  vi psum(n+1);
  psum[0] = 0;
  for (int i = 1; i <= n; ++i) {
    psum[i] = psum[i-1] + (x <= a[i-1] ? 1 : -1);
  }
  i64 r = count_inv(psum);

  return r >= ceil_div((i64)(n+1) * n / 2, 2);
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    b[i] = a[i];
  }

  sort(b,b+n);

  int l = -1, r = n;
  while (r - l > 1) {
    int m = (r+l)/2;
    if (f(b[m])) {
      l = m;
    } else {
      r = m;
    }
  }

  cout << b[l] << endl;

  return 0;
}
