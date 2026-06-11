#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int OO = 1e9;
int brute(int a, int b){
  ll rnk = 1LL * a * b;
  set<int> ss;
  for(int i = 1;i < rnk;i++){
    if(i == a)continue;
    ll x = (rnk - 1) / i;
    while(ss.find(x) != ss.end() || x == b)
      x--;
    if(x)
      ss.insert(x);
  }
//  for(auto el : ss)
//    cout << el << ' ';
//  cout << endl;
  return ss.size();
}
int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
//  cout << 10000 << endl;
//  for(int i = 1;i < 100;i++){
//    for(int j = 1;j < 100;j++){
//      cout << rand() % 10000 + 1 << ' ' << rand() % 10000 + 1 << endl;
//    }
//  }
//  return 0;
  int q;
  cin >> q;
  while(q--){
    int a, b;
    cin >> a >> b;
    ll rnk = 1LL * a * b;
    if(rnk <= 2){
      cout << 0 << endl;
      continue;
    }
    ll res = 0;
    ll prev = -1;
    ll i = 1;
    ll lo, hi;
    lo = 1, hi = rnk - 2;
    while(hi - lo > 20){
      ll mid = (lo + hi) / 2;
      bool b = 0;
      ll j = max(lo, mid - 50000);
      for(;j <= min(hi - 1, mid + 50000);j++){
        if((rnk - 1) / j == (rnk - 1) / (j + 1)){
          hi = j;
          b = 1;
          break;
        }
      }
      if(!b){
        lo = j - 1;
      }
    }
    for(;lo <= hi;lo++){
      if((rnk - 1) / lo == (rnk - 1) / (lo + 1))
        break;
    }
    ll ans = lo + (rnk - 1) / lo - 1;
    if(lo >= a && (rnk - 1) / a != (rnk - 1) / (a + 1) && (rnk - a) / a != (rnk - 1) / (a + 1))
      ans--;
    ll x = (rnk - 1) / b;
    while(x && (rnk - 1) / x > b){
      x++;
    }
    while(x && (rnk - 1) / x < b){
      x--;
    }
    if(x && (rnk - 1) / x == b)
    if((rnk - 1) / (x + 1) == b - 1){
      ans--;
    }
    cout << ans << endl;
  }
  return 0;
}
