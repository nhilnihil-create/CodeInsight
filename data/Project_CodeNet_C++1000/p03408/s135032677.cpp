#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  ll n;
  cin >> n;
  vector<string> a(n);
  rep(i, n)
    cin >> a.at(i);
  
  ll m;
  cin >> m;
  vector<string> b(m);
  rep(i, m)
    cin >> b.at(i);

  ll u,d,score;
  score = 0;
  
  rep(i, n){
    u=0;d=0;
    rep(j, n){
      if(a.at(i) == a.at(j))
        u++;
    }
    rep(j, m){
      if(a.at(i) == b.at(j))
        d++;
    }
    if(score < u-d)
    score = u - d;
  }
  rep(i, m){
    u=0;d=0;
    rep(j, n){
      if(b.at(i) == a.at(j))
        u++;
    }
    rep(j, m){
      if(b.at(i) == b.at(j))
        d++;
    }
    if(score < u-d)
    score = u - d;
  }
  cout << score << endl;
}