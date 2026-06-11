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
int a[MAX_N];
int b[MAX_N];
int ma[MAX_N];
int mb[MAX_N];

int main()
{
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  int r = 0;
  for (int i = 0; i < 29; i++) {
    int t = 1 << i;
    for (int j = 0; j < n; j++) {
      ma[j] = a[j] % (1 << (i+1));
      mb[j] = b[j] % (1 << (i+1));
    }
    sort(mb,mb+n);
    i64 c = 0;
    for (int j = 0; j < n; j++) {
      auto x = lower_bound(mb,mb+n,t-ma[j]);
      auto y = lower_bound(mb,mb+n,2*t-ma[j]);
      c += y - x;
      x = lower_bound(mb,mb+n,3*t-ma[j]);
      y = lower_bound(mb,mb+n,4*t-ma[j]);
      c += y - x;
    }
    if (c % 2 == 1) {
      r |= 1 << i;
    }
  }
  cout << r << endl;

  return 0;
}
