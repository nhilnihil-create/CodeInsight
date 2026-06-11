#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < n; i++)

int main(){
  ll n, k; cin >> n >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a.at(i);
  ll ans = 0;
  for(int i = 40; i >= -1; --i){ //k>=xを満たすようにした時2進数で初めてxi < kiとなるところ
    if(i != -1 && !(k&(1LL<<i))) continue; //kのi桁目は1でないと上の条件を満たせない
    ll tmp = 0;
    for(int j = 40; j >= 0; --j){ //j桁目は0と1どっちが多いか
      ll mask = 1LL<<j;
      ll num = 0;
      for(int l = 0; l < n; l++) if(a[l] & mask) num++;
      
      if(i < j){ //(2進数での)j桁目はkと同じ
        if(k & mask) tmp += mask*(n - num); //j桁目が1ならA[i]のうちj桁目が0のものとxorを考える
        else tmp += mask*num;
      }
      else if(i == j) tmp += mask*num; //xiは必ず0;
      else tmp += mask * max(num, n-num);
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;      
}