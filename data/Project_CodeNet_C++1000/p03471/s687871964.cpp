#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define REP(i, n) for ( int i = 0; i < (n); i++ )
 
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int N, Y;
  cin >> N >> Y;

  bool flag = false;
  for ( int i = 0; i <= N; i++ ) {
    for ( int j = 0; j <= N-i; j++ ) {
      if ( i*10000 + j*5000 > Y ) continue;
      int amari = N - i - j;
      if ( amari*1000 + i*10000 + j*5000 == Y ) {
	cout << i << " " << j << " " << amari << endl;
	return 0;
      }
    }
  }

  cout << -1 << " " << -1 << " " << -1 << endl;

  return 0;
}
