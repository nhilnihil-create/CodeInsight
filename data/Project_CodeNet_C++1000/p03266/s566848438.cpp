#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  ll n,k;
  cin >> n >> k;
  ll cnt = 0,cnts = 0;
  ll ans = 0;
  if(k % 2 == 1){
    cnt += n/k;
    ans += cnt*cnt*cnt;
  }
  else{
    for(int i = 1; i <= n; i++){
      if(i%k == 0) cnt++;
      if(i%k == k/2) cnts++;
    }
    ans += cnt*cnt*cnt;
    ans += cnts*cnts*cnts;
  }
    
  cout << ans << endl;
  
}