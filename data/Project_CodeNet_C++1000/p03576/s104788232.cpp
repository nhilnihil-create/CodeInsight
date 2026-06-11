#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N, K, answer = LLONG_MAX;
  cin >> N >> K;
  pair<int,int> xy[N];
  for (int i = 0; i < N; i++) {
    cin >> xy[i].first >> xy[i].second;
  }
  sort(xy,xy+N);
  for (int i = 0; i < N; i++) {
    for (int j = i+K-1; j < N; j++) {
      int z[j-i+1];
      for (int k = i; k <= j; k++) {
        z[k-i] = xy[k].second;
      }
      sort(z,z+j-i+1);
      for (int k = 0; k+K-1 <= j-i; k++) {
        answer = min(answer,1ll*(xy[j].first-xy[i].first)*(z[k+K-1]-z[k]));
      }
    }
  }
  cout << answer;
}