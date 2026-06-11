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
  ll n, k, a, b, c;
  string s;
  in3(n, k, s);
  a = b = 0;
  if(n == 1 && k == 1 && s == "1"){
    out(1);
    memi;
    return 0;
  }
  while(k > 0){
    if(s[b] == '0')
      k--;
    while(s[b] == s[b + 1]){
      b++;
      if(b == n - 1){
        out(n);
        memi;
        return 0;
      }
    }
    if(b == n - 1){
      out(b);
      memi;
      return 0;
    }
    b++;
  }
  while(s[b] == s[b + 1]){
    b++;
    if(b == n - 1){
      out(n);
      memi;
      return 0;
    }
  }
  c = b - a + 1;
  while(b < n - 1){
    while(s[a] == s[a + 1])
      a++;
    if(s[a] == '0'){
      a++;
      b++;
      while(s[b] == s[b + 1]){
        b++;
        if(b == n - 1)
          break;
      }
      if(b != n - 1 && s[b] == '0'){
        b++;
        while(s[b] == s[b + 1]){
          b++;
          if(b == n - 1)
            break;
        }
      }
      c = max(c, b - a + 1);
    }
    a++;
  }
  out(c);
  memi;
}
