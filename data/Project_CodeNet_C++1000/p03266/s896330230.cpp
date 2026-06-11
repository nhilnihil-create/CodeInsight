#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define ALL(v) (v).begin(), (v).end()
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;
//cout << std::fixed << std::setprecision(15) << y << endl;

int main(){
  ll N, K;
  cin >> N >> K;
  ll zero = 0;
  ll half = 0;
  rep(i,1,N+1){
    if(i % K == 0) zero++;
    if(K % 2 == 0 && i % K == (ll)(K/2)) half++;
  }
  ll ans = pow(zero, 3) + pow(half, 3);
  cout << ans << endl;
  return 0;
}