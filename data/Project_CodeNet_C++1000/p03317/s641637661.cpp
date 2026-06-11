#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair <int, int>;
const double PI = acos(-1);
const ll MOD = 1000000007;

int main() {
  ll N, K;
  cin >> N >> K;
  int ans = 0;
  while(1){
    if(N <= K + (K-1)*ans){
      cout << ans+1 << endl;
      break;
    }
    ans++;
  }
}

/*
int main() {
  ll N, K;
  cin >> N >> K;
  ll cnt=0;
  ll pos1;
  rep(i,N){
    cnt++;
    ll x;
    cin >> x;
    if(x==1) pos1 = cnt-1;
  }

  ll ans_1, ans_2;

  if(pos1 % (K-1) == 0) ans_1 = pos1 / (K-1);
  else ans_1 = pos1 / (K-1) + 1;

  ll pos2 = ans_1 * (K-1) + 1;

  if((N-pos2) % (K-1) == 0) ans_2 = (N-pos2) / (K-1);
  else ans_2 = (N-pos2) / (K-1) + 1;

  //cout << ans_1  << " " <<  ans_2 << endl;
  cout << ans_1 + ans_2 << endl;

}
*/
