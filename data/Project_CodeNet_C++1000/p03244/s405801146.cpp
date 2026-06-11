#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

using namespace std;

int main(void){
  ll n;
  cin >> n;
  
  vector<ll> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  map<ll, ll> b, c;
  for (int i = 0; i < n; i++){
    if (i % 2){
      c[a[i]]++;
    }
    else 
      b[a[i]]++;
  }

  vector<P> bs(0), cs(0);
  for (auto p : b){
    bs.emplace_back(P(p.second, p.first));
  }
  for (auto p : c){
    cs.emplace_back(P(p.second, p.first));
  }
  sort(bs.begin(), bs.end());
  sort(cs.begin(), cs.end());
  
  if (bs[bs.size()-1].second == cs[cs.size()-1].second){
    if (bs.size() == 1){
      if (cs.size() == 1){
        cout << n/2 << endl;
      }
      else {
        cout << n/2 - cs[cs.size()-2].first << endl;
      }
    }
    else {
      if (cs.size() == 1)
        cout << n/2 - bs[bs.size()-2].first << endl;
      else {
        ll s = bs[bs.size()-1].first + cs[cs.size()-2].first;
        ll t = bs[bs.size()-2].first + cs[cs.size()-1].first;
        cout << n - max(s, t) << endl;
      }
    }
  }
  else
    cout << n - bs[bs.size()-1].first - cs[cs.size()-1].first << endl;

  return 0;
}
