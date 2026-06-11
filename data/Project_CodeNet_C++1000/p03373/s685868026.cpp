#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1LL<<60;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  ll ans = INF;
  rep(i,100001){
    ll p = 2 * C * i;
    ll q = max(X - i,0) * A;
    ll r = max(Y - i,0) * B;
    ans = min(ans,p+q+r); 
  }
  cout << ans << endl;




  return 0;
}






