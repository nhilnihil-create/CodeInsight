#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  vector<int> p;
  vector<P> q;
  rep(i,5){
    int c; cin >> c;
    if(c%10 == 0) p.push_back(c);
    else q.push_back({c%10,c});
  }
  sort(q.rbegin(), q.rend());
  
  int ans=0;
  rep(i,p.size()) ans += p[i];
  rep(i,q.size()-1) ans += 10 * ((q[i].second + 9) / 10);
  
  if(q.size() != 0) ans += q[q.size()-1].second;
  
  cout << ans << endl;
  
}