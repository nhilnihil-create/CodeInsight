#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;

int cnt[100] = {0};
void prime_factor(int n){
  for (ll i(2);i*i<=n;i++){
    while(n%i==0){
      ++cnt[i];
      n/=i;
    }
  }
  if (n!=1) cnt[n]++;
}
int main(){
  int N;
  cin>>N;
  for(int i(2);i<=N;i++){
    prime_factor(i); 
  }
  int cnt5(0),cnt25(0),cnt15(0),cnt3(0),cnt75(0);
  for(int i(1);i<10;i++){
    //cout << cnt[i] << " ";
  }
  //cout << endl;
  for(int i(0);i<100;i++){
    if(cnt[i] >= 2) cnt3++; 
    if(cnt[i] >= 4) cnt5++; 
    if(cnt[i] >= 14) cnt15++; 
    if(cnt[i] >= 24) cnt25++; 
    if(cnt[i] >= 74) cnt75++; 
  }
  ll ans(0);
  //cout << cnt5 << " " << cnt25 << " " << cnt75 << endl;
  ans += cnt75;
  ans += (cnt3-1)*(cnt25);
  ans += (cnt5)*(cnt5-1)/2*(cnt3-2);
  ans += cnt15 * (cnt5-1);
  cout << ans << endl;
  return 0;
}

