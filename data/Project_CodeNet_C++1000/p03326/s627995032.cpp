#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<numeric>
using namespace std;
using ll = long long;
int main(){
  int n, m;
  cin >> n >> m;
  vector<ll> x(n), y(n), z(n);
  for(int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> z[i];
  }
  ll ans = 0;
  for(int i = 0; i < 8; i++) {
    vector<ll> sum(n, 0);
    for(int j = 0; j < n; j++) {
      if(i >> 0 & 1){
        sum[j] += x[j];
      }else{
        sum[j] -= x[j];
      }
      if(i >> 1 & 1){
        sum[j] += y[j];
      }else{
        sum[j] -= y[j];
      }
      if(i >> 2 & 1){
        sum[j] += z[j];
      }else{
        sum[j] -= z[j];
      }
    }
    sort(sum.rbegin(), sum.rend());
    ll score = 0;
    for(int j = 0; j < m; j++) {
      score += sum[j];
    }
    ans = max(ans, score);
    //cout << score << " ";
  }
  cout << ans << endl;
  return 0;
}