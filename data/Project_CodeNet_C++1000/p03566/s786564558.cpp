#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); i++)
using ll = long long;
using Graph = vector<vector<int>>;

int main() {
  int N;
  cin >> N;
  int t[N];
  rep(i,N) cin >> t[i];
  int v[N];
  rep(i,N) cin >> v[i];
  
  int speed[N+1];  // speed when max_v switch
  speed[0] = speed[N] = 0;
  
  rep(i,N-1) {  // acceleration
    speed[i+1] = min(speed[i] + t[i], min(v[i], v[i+1]));  // accelerate for t[i] or max_v
  }
 
  rep(i,N-1) {  // deceleration
    speed[N-1-i] = min(speed[N-i] + t[N-1-i], speed[N-1-i]);
  }
 
  double max_v;
  double sum = 0;
 
  rep(i,N) {
    if (speed[i] == v[i] || speed[i+1] == v[i]) {
      max_v = v[i];
    }
    else if (abs(speed[i]-speed[i+1]) == t[i]) {
      max_v = max(speed[i], speed[i+1]);
    }
    else if ((v[i]-speed[i]) + (v[i]-speed[i+1]) <= t[i]) {
      max_v = v[i];
    }
    else {
      max_v = ((double)t[i] + speed[i] + speed[i+1]) / 2;
    }

    sum += max_v * t[i] - pow(max_v - speed[i], 2) / 2 - pow(max_v - speed[i+1], 2) / 2;
  }
 
  printf("%.5f\n", sum);
  return 0;
}
