#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N,C;
  cin >> N >> C;
  int s[N],t[N],c[N];
  bool u[N];
  vector<P> start;
  vector<P> stop;
  for (int i = 0; i < N; i++) {
    u[i] = false;
    cin >> s[i] >> t[i] >> c[i];
    c[i]--;
    start.push_back(make_pair(s[i],c[i]));
    stop.push_back(make_pair(t[i],c[i]));
  }
  sort(start.begin(),start.end());
  sort(stop.begin(),stop.end());

  vector<int> Data(33);
  bool used[33];
  for (int i = 0; i <= 32; i++) {
    Data[i] = -1;
    used[i] = false;
  } 
  

  for (int i = 1; i <= 100060; i++) {
    if (lower_bound(stop.begin(),stop.end(),make_pair(i+1,-100)) - lower_bound(stop.begin(),stop.end(),make_pair(i,-100)) != 0) {
      for (int j = lower_bound(stop.begin(),stop.end(),make_pair(i,-100)) - stop.begin(); j < N; j++) {
        if (stop[j].F != i) {
          break;
        }
        if (lower_bound(start.begin(),start.end(),make_pair(i+1,-100)) - lower_bound(start.begin(),start.end(),make_pair(i,-100)) != 0) {
          
        for (int s = lower_bound(start.begin(),start.end(),make_pair(i,-100)) - start.begin(); s < N; s++) {
          if (start[s].S == stop[j].S) {
            u[j] = true;
          }
          if (s == N-1) {
            break;
          }
          if (start[s+1].F != i) {
            break;
          }
        }
        if (!u[j]) {
          break;
        }
        for (int k = 0; k <= 32; k++) {
          if (Data[k] == stop[j].S) {
            used[k] = true;
            Data[k] = -1;
            break;
          }
        }
        }
        if (j == N-1) {
          break;
        }
        if (stop[j+1].F != i) {
          break;
        }
      }
    }
    
    if (lower_bound(start.begin(),start.end(),make_pair(i+1,-100)) - lower_bound(start.begin(),start.end(),make_pair(i,-100)) != 0) {
      for (int j = lower_bound(start.begin(),start.end(),make_pair(i,-100)) - start.begin(); j < N; j++) {
        for (int k = 0; k <= 32; k++) {
          if (Data[k] == -1) {
            used[k] = true;
            Data[k] = start[j].S;
            break;
          }
        }
        if (j == N-1) {
          break;
        }
        if (start[j+1].F != i) {
          break;
        }
      }
    }

    if (lower_bound(stop.begin(),stop.end(),make_pair(i+1,-100)) - lower_bound(stop.begin(),stop.end(),make_pair(i,-100)) != 0) {
      for (int j = lower_bound(stop.begin(),stop.end(),make_pair(i,-100)) - stop.begin(); j < N; j++) {
        if (u[j]) {
          break;
        }
        for (int k = 0; k <= 32; k++) {
          if (Data[k] == stop[j].S) {
            used[k] = true;
            Data[k] = -1;
            break;
          }
        }
        if (j == N-1) {
          break;
        }
        if (stop[j+1].F != i) {
          break;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= 32; i++) {
    if (used[i]) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
