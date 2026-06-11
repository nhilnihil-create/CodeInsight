#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;

int main() {
  int N,T;
  cin >> N >> T;
  
  bool x = false;
  int cost = 1000;
  int c,t;
  rep(i,N){
    cin >> c >> t;
    if(t<=T){
      cost = min(c, cost);
      x = true;
    }
  }
  
  if(x){
    cout << cost << endl;
  }
  else{
    cout << "TLE" << endl;
  }
}      
       