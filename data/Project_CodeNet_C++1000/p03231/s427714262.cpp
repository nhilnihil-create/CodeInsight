#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
ll gcd(ll x,ll y){
  if(x%y == 0) return y;
  else return gcd(y,x%y);
}
ll lcm(ll x,ll y){
  return x/gcd(x,y)*y;
}
int main(){
  cin.tie(0);ios::sync_with_stdio(false);
  ll N,M,i,j;string s,t;cin >> N >> M >> s >> t;
  ll a = N/gcd(N,M),b = M/gcd(N,M);
  for(i=0;i*a<N;i++){
    if(s[i*a] != t[i*b]){
      cout << "-1\n";return 0;
    }
  }
  cout << lcm(N,M) << "\n";
}