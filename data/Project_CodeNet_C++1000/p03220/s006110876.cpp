#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n, t, a;
  cin >> n >> t >> a;
  a *= 1000;
  vector<int> vec(n);
  int c = 0;
  int d = INF;
  rep(i, n) {
    cin >> vec[i];
    vec[i] = t * 1000 - vec[i] * 6;
    if (abs(vec[i] - a) < d) {
      d = abs(vec[i] - a);
      c = i;
    }
  }
  cout << c+1 << endl;

  return 0;
}