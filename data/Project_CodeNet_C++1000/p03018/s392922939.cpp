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
  ll a, b, c, x, n;
  string s, t, u;
  in(s);
  a = 0;
  t = "";
  n = s.size();
  while(a < n){
    if(s[a] == 'A'){
      u = 'A';
      t = t + u;
    }
    else if(s[a] == 'B'){
      if(a < n - 1 && s[a + 1] == 'C'){
        u = 'T';
        t = t + u;
        a++;
      }
      else{
        u = 'B';
        t = t + u;
      }
    }
    else{
      u = 'C';
      t = t + u;
    }
    a++;
  }
  x = 0;
  t += "XXX";
  n = t.size();
  a = 0;
  x = 0;
  rep(i, n){
    if(t[i] == 'A')
      a++;
    else if(t[i] == 'T')
      x += a;
    else
      a = 0;
  }
  out(x);
  memi;
}