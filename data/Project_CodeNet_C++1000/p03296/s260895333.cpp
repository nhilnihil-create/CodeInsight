#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  int cnt = 0;
  int color = 10000;
  REP(i,n-1){
    if(a[i]==a[i+1]){
      a[i+1] = color;
      color--;
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
