#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;

int main(){
  int n;
  cin >> n;
  int f[n][10];
  for(int i=0; i<n; ++i) for(int j=0; j<10; ++j){
    cin >> f[i][j];
  }
  int p[n][11];
  for(int i=0; i<n; ++i) for(int j=0; j<11; ++j){
    cin >> p[i][j];
  }
  int ans = -INF;
  for(int i=1; i<(1<<10); ++i){
    int score = 0;
    for(int j=0; j<n; ++j){
      int cnt = 0;
      for(int k=0; k<10; ++k){
        if((i>>k & 1) && f[j][k]) ++cnt;
      }
      score += p[j][cnt];
    }
    ans = max(score, ans);
  }
  cout << ans << endl;
}