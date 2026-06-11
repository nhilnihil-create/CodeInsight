#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i, a, n) for(ll i = a; i < (ll)(n); i++)
#define memi cout << endl
#define kono(n) cout << fixed << setprecision(n)
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define hina cout << ' '
#define in(n) cin >> n
#define in2(n, m) cin >> n >> m
#define in3(n, m, l) cin >> n >> m >> l
#define out(n) cout << n
const ll mei = (ll)1e9 + 7;

int main(){
  ll a, b, c, k;
  char d;
  string s, u, x;
  in2(s, k);
  vector<string> t;
  rep(i, s.size()){
    u = s[i];
    b = 0;
    rep(j, t.size()){
      if(u == t[j])
        b++;
    }
    if(b == 0)
      t.pb(u);
  }
  rep(i, s.size() - 1){
    u = s[i];
    x = s[i + 1];
    u = u + x;
    b = 0;
    rep(j, t.size()){
      if(u == t[j])
        b++;
    }
    if(b == 0)
      t.pb(u);
  }
  rep(i, s.size() - 2){
    u = s[i];
    x = s[i + 1];
    u = u + x;
    x = s[i + 2];
    u = u + x;
    b = 0;
    rep(j, t.size()){
      if(u == t[j])
        b++;
    }
    if(b == 0)
      t.pb(u);
  }
  rep(i, s.size() - 3){
    u = s[i];
    x = s[i + 1];
    u = u + x;
    x = s[i + 2];
    u = u + x;
    x = s[i + 3];
    u = u + x;
    b = 0;
    rep(j, t.size()){
      if(u == t[j])
        b++;
    }
    if(b == 0)
      t.pb(u);
  }
  rep(i, s.size() - 4){
    u = s[i];
    x = s[i + 1];
    u = u + x;
    x = s[i + 2];
    u = u + x;
    x = s[i + 3];
    u = u + x;
    x = s[i + 4];
    u = u + x;
    b = 0;
    rep(j, t.size()){
      if(u == t[j])
        b++;
    }
    if(b == 0)
      t.pb(u);
  }
  sort(all(t));
  out(t[k - 1]);
  memi;
}