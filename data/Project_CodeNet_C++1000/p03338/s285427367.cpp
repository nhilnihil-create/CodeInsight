#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll N = 0,X = 0;
  string S;
  cin >> N >> S;
  map<char,ll> Aq;
  map<char,ll> Bq;
  rep(I,S.size()-1){
    ll ans = 0;
    Aq.clear();
    Bq.clear();
    rep(J,I+1){
      Aq[S[J]]++;
    }
    rep(K,N-1-I){
      Bq[S[K+I+1]]++;
    }
    if(Aq['a'] > 0 && Bq['a'] > 0)ans++;
    if(Aq['b'] > 0 && Bq['b'] > 0)ans++;
    if(Aq['c'] > 0 && Bq['c'] > 0)ans++;
    if(Aq['d'] > 0 && Bq['d'] > 0)ans++;
    if(Aq['e'] > 0 && Bq['e'] > 0)ans++;
    if(Aq['f'] > 0 && Bq['f'] > 0)ans++;
    if(Aq['g'] > 0 && Bq['g'] > 0)ans++;
    if(Aq['h'] > 0 && Bq['h'] > 0)ans++;
    if(Aq['i'] > 0 && Bq['i'] > 0)ans++;
    if(Aq['j'] > 0 && Bq['j'] > 0)ans++;
    if(Aq['k'] > 0 && Bq['k'] > 0)ans++;
    if(Aq['l'] > 0 && Bq['l'] > 0)ans++;
    if(Aq['n'] > 0 && Bq['n'] > 0)ans++;
    if(Aq['o'] > 0 && Bq['o'] > 0)ans++;
    if(Aq['p'] > 0 && Bq['p'] > 0)ans++;
    if(Aq['q'] > 0 && Bq['q'] > 0)ans++;
    if(Aq['r'] > 0 && Bq['r'] > 0)ans++;
    if(Aq['s'] > 0 && Bq['s'] > 0)ans++;
    if(Aq['t'] > 0 && Bq['t'] > 0)ans++;
    if(Aq['u'] > 0 && Bq['u'] > 0)ans++;
    if(Aq['v'] > 0 && Bq['v'] > 0)ans++;
    if(Aq['w'] > 0 && Bq['w'] > 0)ans++;
    if(Aq['x'] > 0 && Bq['x'] > 0)ans++;
    if(Aq['y'] > 0 && Bq['y'] > 0)ans++;
    if(Aq['z'] > 0 && Bq['z'] > 0)ans++;
    if(Aq['m'] > 0 && Bq['m'] > 0)ans++;
    X = max(X,ans);
  }
  cout << X;
}