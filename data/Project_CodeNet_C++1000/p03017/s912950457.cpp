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
  ll n, a, b, c, d, e, f;
  in3(n, a, b);
  string s;
  in3(c, d, s);
  a--;
  b--;
  c--;
  d--;
  bool h, k, l;
  h = true;
  k = false;
  l = true;
  if(c < d)
    k = true;
  rep2(i, b - 1, d){
    if(s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.')
      k = true;
  }
  rep2(i, a, c - 1){
    if(s[i + 1] == '#' && s[i + 2] == '#')
      h = false;
  }
  rep2(i, b, d - 1){
    if(s[i + 1] == '#' && s[i + 2] == '#')
      l = false;
  }
  if(k && h && l)
    out("Yes");
  else
    out("No");
  memi;
}