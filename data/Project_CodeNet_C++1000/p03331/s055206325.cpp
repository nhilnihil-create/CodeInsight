#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

ll digit_sum(ll x){
  ll ret = 0;
  string s = to_string(x);
  for(char c: s){
    ret += c - '0';
  }
  return ret;
}

int main(){
  cout << setprecision(10);
  ll N; cin >> N;

  ll ans = 10000000000;
  for(ll i = 1; i <= N; i++){
    ll A = i;
    ll B = N - i;
    if(B == 0) continue;

    ans = min(ans, digit_sum(A) + digit_sum(B));
  }
  cout << ans << endl;
}
