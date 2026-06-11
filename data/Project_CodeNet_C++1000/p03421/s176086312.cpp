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

i64 n,a,b;

int main()
{
  cin >> n >> a >> b;

  if (a+b > n+1 || a*b < n) {
    cout << -1 << endl;
  } else {
    vector<i64> l;
    for (i64 i = a-1; i >= 0; i--) {
      l.pb(a*b-i);
    }
    i64 m = n - a;
    for (i64 i = 1; i <= a && m > 0; i++) {
      for (i64 j = b-2; j >= 0 && m > 0; j--) {
        l.pb(a*j+i);
        m--;
      }
    }
    vector<i64> cl = l;
    sort(cl.begin(),cl.end());
    for (int i = 0; i < (int)l.size(); i++) {
      cout << lower_bound(cl.begin(),cl.end(),l[i]) - cl.begin() + 1
           << (i+1==(int)l.size()?'\n':' ');
    }
  }

  return 0;
}
