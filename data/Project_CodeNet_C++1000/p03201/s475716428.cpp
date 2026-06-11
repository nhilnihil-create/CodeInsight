#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
  ll N; cin >> N;
  map <ll, int> mp;
  
  if(N == 1){
    cout << 0 << endl;
    return 0;
  }
  
  ll cnt = 0;
  vector<ll> A(N);
  for(int i = 0; i < N; ++i){
    cin >> A.at(i);
    mp[A.at(i)]++;
  }
  
  sort(A.begin(), A.end());
  
  for(int i = N-1; i > 0; --i){
    if(mp[A.at(i)]==0) continue;
    ll x = 1;
    while(x <= A.at(i)) x*=2;
    ll d = x - A.at(i);
    
    if(d!=A.at(i) && mp[d]>0){
      cnt++;
      mp[A.at(i)]--;
      mp[d]--;
    }
    else if(d==A.at(i) && mp[d]>1){
      cnt++;
      mp[d] -= 2;
    }
  }
  cout << cnt << endl;
}
