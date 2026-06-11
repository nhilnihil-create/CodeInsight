#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;



int main(){
  ll n,m;
  cin>>n >>m;
  ll ans=0;
  vector<pair<ll,ll>> p(n);
    for(int i=0;i<n;i++){
    long long  a,b;
    cin >> a >> b;
    p[i] = make_pair(a,b);
  }
  sort(p.begin(),p.end());

  rep(i,n){
    if(m>p[i].second){
      m-=p[i].second;
      ans+=p[i].first*p[i].second;
      }else{
        ans+=m*p[i].first;
        break;
      }
  }
  cout << ans << endl;
}