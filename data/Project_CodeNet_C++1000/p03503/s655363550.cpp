#include <bits/stdc++.h>
#include <limits>
#include <math.h>
#include <cmath>
#include <cctype>
#include <cstdio>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll> ;
using vs = vector<string>;
using vb = vector<bool>;
using vll = vector<long long>;
using vvll = vector<vector<long long >>;
#define PI  3.1415926535
#define rep(i, k, n) for(ll i = k; i < n; i++)

int main(){
  ll n; cin >> n;
  vvll shift (n, vll(10));
  vvll profit (n, vll(11));
  
  rep(i, 0, n){
    rep(j, 0, 10){
      cin >> shift[i][j];
    }
  }
  
  rep(i, 0, n){
    rep(j, 0, 11){
      cin >> profit[i][j];
    }
  }
  ll ans = -100000000000;
  for(ll bit = 1; bit < (1<<10); bit++){
    ll res = bit;
    vll s (0);
    while(res > 1){
      s.emplace_back(res%2);
      res /= 2;
    }
    s.emplace_back(1);
    
    while(s.size() < 10){
      s.emplace_back(0);
    }
    
    ll score = 0;
    rep(i, 0, n){
      ll ju = 0;
      rep(j, 0, 10){
        if(shift[i][j] && s[j]){
          ju++;
        }
      }
      score += profit[i][ju];
    }
    
    ans = max(ans, score);
  }
  cout << ans << endl;
}
      
    
  
  
    
    