#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main() {
  ll n,m;
  cin>>n>>m;
  
  vector<ll> X(m);
  rep(i,m) cin>>X[i];
  
  if(n>=m) cout<<0<<endl;
  else{
    vector<ll> Y;
    sort(ALL(X));
    rep(i,m-1){
      Y.push_back(X[i+1]-X[i]);
    }
    sort(ALL(Y));
    rep(i,n-1) Y.pop_back();
    ll sum=0;
    for(auto t:Y) sum+=t;
    cout<<sum<<endl;
  }
  
  return 0;
}