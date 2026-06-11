#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;
//cout << std::fixed << std::setprecision(15) << y << endl;

int main(){
  ll N;  cin >> N;
  VL a(N); 
  rep(i,0,N){
    cin >> a[i];
    a[i] -= i + 1;
  }
  sort(ALL(a));

  ll ans = INF;  ll b;
  if(N % 2 == 0) b = (a[N/2]+a[N/2-1])/2;
  else b = a[(N-1)/2];
  rep(i,b-1,b+2){
    ll tmp = 0; 
    rep(j,0,N){
      tmp += abs(a[j] - i);
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}