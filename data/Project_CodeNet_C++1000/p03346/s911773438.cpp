#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){

  ll n;
  cin >> n;
  vector<ll> v(n);
  rep(i,n)cin >> v[i];
  vector<ll> cnt(n+1,0);
  rep(i,n){
    if(cnt[v[i]-1] > 0){
      cnt[v[i]] = cnt[v[i]-1]+1;
    }else{
      cnt[v[i]] = 1;
    }
  }
  cout << n-*max_element(ALL(cnt)) << endl;





  return 0;
}