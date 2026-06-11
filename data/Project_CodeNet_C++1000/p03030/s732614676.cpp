#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n; cin >> n;
  vector<tuple<string, ll, ll>> t;
  
  rep(i,n){
    string s; ll p;
    cin >> s >> p;
    t.push_back(make_tuple(s, -p, i+1));
  }
  
  sort(t.begin(),t.end());
  
  rep(i, n)
    cout << get<2>(t[i]) << endl;
}