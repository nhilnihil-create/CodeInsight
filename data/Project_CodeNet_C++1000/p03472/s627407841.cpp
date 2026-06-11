#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, H;
  cin >> N >> H;
  vector<int> a(N), b(N);
  for (int i = 0; i < N; i++){
    cin >> a[i] >> b[i];
  }
  vector<pair<int, int>> d;
  for (int i = 0; i < N; i++){
    d.push_back(make_pair(a[i], 0));
    d.push_back(make_pair(b[i], 1));
  }
  sort(d.begin(), d.end());
  reverse(d.begin(), d.end());
  int ans = 0;
  for (int i = 0; i <= N * 2; i++){
    if (d[i].second == 1){
      H -= d[i].first;
      ans++;
      if (H <= 0){
        break;
      }
    } else {
      ans += (H + d[i].first - 1) / d[i].first;
      break;
    }
  }
  cout << ans << endl;
}