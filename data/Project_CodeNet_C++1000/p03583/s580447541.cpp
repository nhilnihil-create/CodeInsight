#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(ll i = (m); i < (n); ++i)

#define INF 1e9

int main(){
  ll N;
  cin >> N;
  FOR(h, 1, 3501){
    FOR(n, 1, 3501){
      ll s = (4*h*n - N*n - N*h);
      if(s == 0) continue;
      ll w = N*h*n / s;
      if(w <= 0) continue;
      if(4*h*n*w == N*(n*w+h*w+h*n)){
        cout << h << " " << n << " " << w << endl;
        return 0;
      }
    }
  }
  cout << "finish" << endl;
  return 0;
}
