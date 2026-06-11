#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

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