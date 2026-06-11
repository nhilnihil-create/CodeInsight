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
ll INF=1e18+5;

int main(){
  ll N, K;
  cin >> N >> K;
  double p = 1.0/(double)(N);
  double ans = 0.0;
  rep(i,0,N){
    ll s = i+1;
    ll cnt = 0;
    while(s < K){
      s *= 2;
      cnt++;
    }
    ans += p/(double)(pow(2,cnt));
  }
  cout << std::fixed << std::setprecision(12) << ans << endl;
  return 0;
}