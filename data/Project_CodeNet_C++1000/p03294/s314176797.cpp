#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>

int main(){
  ll N;  cin >> N;
  VL a(N); 
  ll ans = 0;
  rep(i,0,N){
    cin >> a[i];
    ans += a[i] - 1;
  }
  cout << ans << endl;
  return 0;
}