#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  int N;
  cin >> N;
  vector<int> h(N), g(N);
  rep(i,N){
    cin >> h.at(i);
    g.at(i) = h.at(i);
  }
  int ans = 0;
  rep(i,100){
    rep(j,N){
      if(j == 0 && h.at(j) > 0){
        ans ++;
        g.at(j) --;
      }
      else if(h.at(j) > 0){
        if(h.at(j-1) == 0){
          ans ++;
        }
        g.at(j) --;
      }
    }
    h = g;
  }
  cout << ans << endl;
}