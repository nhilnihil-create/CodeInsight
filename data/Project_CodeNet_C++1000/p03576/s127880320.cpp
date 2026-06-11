#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAX = 1ll << 62;

int main(){
  int N, K;
  cin >> N >> K;
  
  vector<ll> x(N);
  vector<ll> y(N);
  for(int i = 0; i < N; i++){
    cin >> x[i] >> y[i];
  }
  
  ll x1, x2, y1, y2;
  ll s = MAX;
  for(int i = 0; i < N - 1; i++){
    x1 = x[i];
    for(int j = i + 1; j < N; j++){
      x2 = x[j];
      for(int k = 0; k < N - 1; k++){
        y1 = y[k];
        for(int m = k + 1; m < N; m++){
          y2 = y[m];
          
          ll l, r, d, u;
          l = min(x1, x2);
          r = max(x1, x2);
          d = min(y1, y2);
          u = max(y1, y2);
          
          int cnt = 0;
          for(int i = 0; i < N; i++){
            if(min(l, r) <= x[i] && x[i] <= r && d <= y[i] && y[i] <= u){
              cnt++;
            }
          }
          
          if(cnt >= K && (r - l) * (u - d) <= s){
            s = (r - l)*(u - d);
          }
        }
      }
    }
  }
  
  cout << s << endl;
}