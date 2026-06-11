#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

ll mpow(ll x, ll n){
  if(n == 0)
    return 1;
 
  if(n % 2 == 0)
    return mpow(x * x, n / 2);
  else
    return x * mpow(x, n - 1);
}


int main(){
  cout << setprecision(10);
  ll N, K;
  cin >> N >> K;
  int max_digit = 50;
  map<int, ll> m;
  for(int i = 0; i <= max_digit; i++){
    m[i] = 0;
  }

  for(int i = 0; i < N; i++){
    ll A;
    cin >> A;
    int index = 0;
    while(A > 0){
      m[index] += A%2;
      A /= 2;
      index++;
    }
  }

  for(ll i = max_digit; i >= 0; i--){
    if(K < mpow(2, i)) continue;

    if(m[i] > N-m[i]){
      // 1の方が多い場合は0にする方がとく
      // f[i] = m[i]になる 
    } else if(m[i] < N-m[i]){
      // 0の方が多い場合は1にする
      // f[i] = N - m[i] になる
      // Kが減る
      m[i] = N - m[i];
      K = K - mpow(2,i);
    } 
  }

  ll ans = 0;
  for(ll i = 0; i < m.size(); i++){
    ans += m[i] * mpow(2,i);
  }
  cout << ans << endl;
}
