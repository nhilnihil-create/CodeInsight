#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll ss(ll x){
  ll d = 0;
  while(x > 0){
    d+=x%10;
    x/=10;
  }
  return d;
}

bool is(ll x, ll y, ll p, ll q){
  return x * 1ll * q > y * 1ll * p; 
}

int main(){
  fastIO;
  vector<ll> cand;
  int len = 1;
  ll p;
  for(int t = 1; t <= 200; t ++ ){
    if(t == 10) len ++ ;
    if(t == 100) len ++ ;
    p = t;
    cand.push_back(t);
    for(int j = 1 ; j <= 16; j ++ ){
      if(len + j > 16) continue;
      p *= 10ll;
      p += 9;
      cand.push_back(p);
    }
  }
  sort(cand.begin(), cand.end());
  cand.resize(unique(cand.begin(), cand.end()) - cand.begin());
  bool valid;
  int k;
  cin >> k;
  for(int i = 0 ; i < cand.size(); i ++ ){
    valid = true;
    for(int j = i + 1; j < cand.size(); j ++ ){
      if(is(cand[i], ss(cand[i]), cand[j], ss(cand[j]))){
        valid = false;
        break;
      }
    }
    if(valid){
      cout << cand[i] << "\n";
      k -- ;
      if(k == 0) return 0;
    }
  }
  return 0;
}