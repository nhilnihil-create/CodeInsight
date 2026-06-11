#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
const int INF = 1001001001;

int main(){
  int n;
  cin >> n;
  bool open[100][10];
  rep(i, n){
    rep(j, 10){
      int f;
      cin >> f;
      open[i][j] = f;
    }
  }
  int p[100][11];
  rep(i, n){
    rep(j, 11){
      cin >> p[i][j];
    }
  }
  int ans;
  for(int i = 1; i < (1 << 10); i++){
    bitset<10> s(i);
    int cnt[100];
    fill(cnt, cnt + 100, 0);
    for(int j = 0; j < 10; j++){
      if(s.test(j)){
        for(int k = 0; k < n; k++){
          if(open[k][j]) cnt[k]++;
        }
      }
    }
    int tmp = 0;
    for(int j = 0; j < n; j++){
      tmp += p[j][cnt[j]];
    }
    if(i == 1) ans = tmp;
    else ans = max(ans, tmp);
  }
  cout << ans <<endl;
      
}