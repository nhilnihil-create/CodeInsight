#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e16;

signed main(){
  
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int A, B, Q;
  cin >> A >> B >> Q;
  
  vector<int> S(A);
  for( int i = 0; i < A; i++ ) cin >> S.at(i);
  vector<int> T(B);
  for( int i = 0; i < B; i++ ) cin >> T.at(i);
  
  for( int i = 0; i < Q; i++ ){
    int X;
    cin >> X;
    
    int RS = lower_bound(S.begin(), S.end(), X) - S.begin();
    int LS = RS-1;
    int RT = lower_bound(T.begin(), T.end(), X) - T.begin();
    int LT = RT-1;
    
    int ans = INF;
    //どっちも右
    if( RS < A && RT < B ) ans = max(S.at(RS), T.at(RT)) - X;
    //どっちも左
    if( LS >= 0 && LT >= 0 ) ans = min( ans, X-min(S.at(LS),T.at(LT)) );
    //左の神社と右の寺
    if( LS >= 0 && RT < B ){
      ans = min({ans, (X-S.at(LS))*2+(T.at(RT)-X), (X-S.at(LS))+(T.at(RT)-X)*2});
    }
    //右の神社と左の寺
    if( RS < A && LT >= 0 ){
      ans = min({ans, (S.at(RS)-X)*2+(X-T.at(LT)), (S.at(RS)-X)+(X-T.at(LT))*2});
    }
    cout << ans << endl;
    
  }
}
