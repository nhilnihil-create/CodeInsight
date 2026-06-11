#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1000000007;
using Graph = vector<vector<int>>;

signed main(){
  int D, G;
  cin >> D >> G;
  vector<int> P(D);
  vector<int> C(D);
  for( int i = 0; i < D; i++ ) cin >> P.at(i) >> C.at(i);

  int ans = 5000;
  for (int bit = 0; bit < (1<<D); ++bit) {
    int now = 0;
    int score = 0;
    for (int i = 0; i < D; ++i) {
      if (bit & (1<<i)) { // i番目のbitが立っていれば
      now += P.at(i);
      score += P.at(i)*100*(i+1) + C.at(i);
      }
    }
    if( score >= G ){
      ans = min(ans, now);
      continue;
    }

    for( int i = D-1; i >= 0; i-- ){
      if( score >= G ) break;
      if (bit & (1<<i)) continue;
      for( int j = 1; j < P.at(i); j++ ){
        if( (i+1)*100*j >= G-score ){
          now += j;
          score += (i+1)*100*j;
          break;
        }
      }
    }
    if( score >= G ){
      ans = min(ans, now);
    }
  }

  cout << ans << endl;


 }
