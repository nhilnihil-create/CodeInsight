#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)

int main() {
  ll n;cin >> n;
  vector<ll> e(100001,0);
  vector<ll> o(100001,0);

  ll emax = -1;
  ll omax = -1;
  ll eid = -1;
  ll oid = -1;
  rep(i,n){
    ll num;cin >> num;
    if( i%2 == 0 ){
      o.at(num)++;
      if( omax < o.at(num) ){
        omax = max(omax,o.at(num));
        oid = num;
      }
    }else{
      e.at(num)++;
      if( emax < e.at(num) ){
        emax = max(emax,e.at(num));
        eid = num;
      }
      
    }
  }
  sort(o.begin(),o.end());
  sort(e.begin(),e.end());

  ll e1 = e.back();
  ll e2 = e.at(e.size()-2);
  ll o1 = o.back();
  ll o2 = o.at(o.size()-2);

  if( eid != oid ){
    cout << n - e1 - o1 << endl;
  }else{
    cout << min((n - e1 - o2),(n - e2 - o1 ) ) << endl;
  }
  
  return 0;
}
