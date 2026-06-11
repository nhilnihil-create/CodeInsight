#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,k;
  cin >> n >> k;
  ll cnt = 0;
  ll num[k];
  for(int i=0 ; i<k ; i++){
    num[i] = 0;
  }
  for(int i=1 ; i<=n ; i++){
    num[i%k]++;
  }
  ll res = 0;
  for(int a=0 ; a<k ; a++){
    ll b = (k-a) % k;
    ll c = (k-a) % k;
    if((b+c) % k != 0) continue;
    res += num[a] * num[b] * num[c];
  }
  cout << res << endl;
  return 0;
}
