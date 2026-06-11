#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll N; cin >> N;
  ll sum = 0LL;
  vector<ll> a(N);
  bitset<4000001> b(1);
  for(ll i = 0; i < N; i++){
    cin >> a[i];
    sum += a[i];
    b |= (b << a[i]);
  }
  ll hs = sum/2 + sum%2;
  while(1){
    if(b[hs]) {
      cout << hs << endl;
      break;
    }
    hs++;
  }
}