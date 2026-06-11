#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  ll N;
  cin >> N;
  rep(h,1,3501){
    rep(n,h,3501){
      ll w = N*h*n,p = 4*h*n-N*(h+n);
      if(p == 0) continue;
      if(w%p == 0 && p > 0){
        w /= p;
        cout << h << " " << n << " " << w << endl;
        return 0;
      }
    }
  }
}