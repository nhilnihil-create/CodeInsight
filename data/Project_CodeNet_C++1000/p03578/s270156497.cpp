#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n;
  cin >> n;
  
  multiset<ll> d;
  rep(i,n){
    ll c;
    cin >> c;
    d.insert(c);
  }

  int m;
  cin >> m;
  vector<ll> t(m);
  rep(i,m) cin >> t.at(i);

  string ans = "YES";
  rep(i,m){
    ll now = t.at(i);
    if(d.find(now)==d.end()){ans="NO"; break;}
    else d.erase(d.find(now));
  }

  cout << ans;
}