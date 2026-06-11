#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  ll d,n; cin >> d >> n;
  
  if(d==0){
    if(n<100){
      cout << n << endl;
      return 0;
    }
    else{
      cout << n+1 << endl;
      return 0;
    }
  }
  if(d==1){
    if(n<100){
      cout << 100*n << endl;
      return 0;
    }
    else{
      cout << 100*n+100<< endl;
      return 0;
    }
  }
  if(d==2){
    if(n<100){
      cout << 10000*n << endl;
      return 0;
    }
    else{
      cout << 10000*n+10000 << endl;
      return 0;
    }
  }
}