#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  ll N,A,B; cin >> N >> A >> B;
  ll ans = 0;
  for(ll i = 1; i <= N; i++){
    ll check = 0;
    check += i % 10;
    check += (i / 10) % 10;
    check += (i / 100) % 10;
    check += (i / 1000) % 10;
    check += (i / 10000) % 10;
    if(check >= A && check <= B){
      ans += i;
    }
  }
  cout << ans;
}
  