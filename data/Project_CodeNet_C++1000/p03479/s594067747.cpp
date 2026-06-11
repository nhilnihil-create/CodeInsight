#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){

  ll l,r;
  cin >> l >> r;
  ll res = 0;
  while(l <= r && l > 0){
    l *= 2;
    res++;
  }
  cout << res << endl;



  return 0;
}
