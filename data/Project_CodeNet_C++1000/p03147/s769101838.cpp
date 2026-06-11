#include<bits/stdc++.h>
using namespace std;
int main() {
  int N, numin, numax, res = 0;
  cin >> N;
  vector<int> vec(N);
  for(int i = 0; i < N; i++) cin >> vec[i];
  while(true) {
    while(true) {
      if(vec[0] == 0 && !vec.empty()) {
        vec.erase(vec.begin());
      }
      else {
        break;
      }
    }
    N = vec.size();
    for(int i = 0; i < N; i++) {
      if(vec[i] != 0) {
        numin = min(vec[i], numin);
      }
      else {
        break;
      }
    }
    for(int i = 0; i < N; i++) {
      if(vec[i] != 0) {
        vec[i] -= numin;
      }
      else {
        break;
      }
    }
    if(vec.empty()) break;
    else res += numin;
  }
  cout << res << endl;
}