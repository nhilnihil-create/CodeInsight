#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<pair<int, int>> red(N);
  vector<pair<int, int>> blue(N);
  for (int i = 0; i < N; i++) cin >> red[i].second >> red[i].first;
  sort(red.begin(), red.end());
  reverse(red.begin(), red.end());
  for (int i = 0; i < N; i++) {
    int a = red[i].first;
    red[i].first = red[i].second;
    red[i].second = a;
  }
  for (int i = 0; i < N; i++) cin >> blue[i].first >> blue[i].second;
  sort(blue.begin(), blue.end());
  
  vector<bool> seen(N, false);
  
  int ans = 0;
  for (int i = 0; i < N; i++) { //blue
    for (int j = 0; j < N; j++) {
      if (red[j].first < blue[i].first && red[j].second < blue[i].second && !seen[j]) {
        seen[j] = true;
        ans++;
        break;
      }
    }
  }
  
  cout << ans << endl;        
}