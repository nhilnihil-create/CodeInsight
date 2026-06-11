#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;


int main(){
  ll K;
  cin>>K;
  vector<ll> A(K);
  for(int i(0);i<K;i++){
    cin>>A[i];
  }
  if(A[K-1] != 2){
    cout << -1 << endl;
    return 0;
  }
  ll nowl(2),nowh(2);
  for(int i(K-1);i>=1;i--){
    ll l = nowl,h = nowh+(A[i]-1);
    ll next1(-1),next2(-1);
    ll li = (l+A[i-1]-1)/A[i-1];
    ll hi = h/A[i-1];
    if(li > hi){
      cout << -1 << endl;
      return 0;
    }
    next1 = li*A[i-1];
    next2 = hi*A[i-1];


    nowl = next1;
    nowh = next2;
  }
  cout << nowl << " " << nowh+A[0]-1 << endl;
  return 0;
}

