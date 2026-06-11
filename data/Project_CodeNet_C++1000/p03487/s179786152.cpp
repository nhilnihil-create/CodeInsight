#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;
int main(){
  int n; cin >> n;
  ll ans = 0;
  vector<ll> a(n,0);
  rep(i,n){
    ll x; cin >> x;
    if(x>n){
      ans++;
    }else{
      a.at(x-1)++;
    }
  }

  rep(i,n){
    if(a.at(i)<i+1) ans+=a.at(i);
    else if(a.at(i)>i+1) ans+=a.at(i)-i-1;
  }

  cout << ans << endl;
}
