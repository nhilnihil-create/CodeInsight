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
  VL a(N+2, 0); rep(i,1,N+1) cin >> a[i];
  
  VL suma(N+2, 0);
  ll cnt = 0;
  rep(i,1,N+1){
    cnt += abs(a[i] - a[i-1]);
    suma[i] = cnt;
  }
  suma[N+1] = cnt + abs(a[N] - 0);
  
  rep(i,1,N+1){
    cout << suma[N+1] - abs(a[i] - a[i-1]) - abs(a[i+1] - a[i]) + abs(a[i+1] - a[i-1]) << endl;
  }
  return 0;
}