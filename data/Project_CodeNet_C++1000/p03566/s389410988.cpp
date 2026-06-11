#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)

int main(){
  int N;
  cin >> N;
  double t, v[N+1], ta[N];
  rep(i, N) {
    cin >> t;
    if(!i) ta[i] = t;
    else ta[i] = ta[i-1] + t;
  }
  rep(i, N) cin >> v[i];
  v[N] = 0.0, t = 0;
  int pos = 0;
  double ans = 0, vel = 0.0;
  while(t < ta[N-1]){
    bool can1 = true, can0 = true;
    for(int i = pos; i < N; i++){
      if(ta[i] - t  == vel - v[i+1]) can0 = false;
      if(ta[i] - t  - (vel - v[i+1]) == 1.0) can1 = false;
    }
    if(!can0) {
      ans += vel - 0.5;
      vel--;
    }
    else if(can0 && !can1){
      if(vel == v[pos]) ans += vel;
      else ans += vel + 0.25;
    }
    else if(vel < v[pos]){
      ans += vel + 0.5;
      vel++;
    } else ans += vel;
    t++;
    if(t >= ta[pos]) pos++;
  }
  printf("%6f\n", ans);
  return 0;
}
