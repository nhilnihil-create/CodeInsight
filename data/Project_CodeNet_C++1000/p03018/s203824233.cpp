#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1000000007;

signed main() {
  string S;
  cin >> S; 
  int cnt = 0;
  int ans = 0;
  for( int i = S.size()-1; i >= 0; i-- ){
    if( i > 0 && S.at(i) == 'C' && S.at(i-1) == 'B' ){
      cnt++;
      i--;
    }else if( S.at(i) == 'A' ) ans += cnt;
    else cnt = 0;
  }
  cout << ans << endl;
}