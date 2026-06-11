#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  
  vector<vector<int>> sw(N+1);
  
  for (int i = 1; i <= M; i++) {
    int k;
    cin >> k;
    
    for (int j = 0; j < k; j++) {
      int s;
      cin >> s;
      sw[s].push_back(i);
    }
  }
  
  

  vector<int> p(M+1);
  for (int i = 1; i <= M; i++) {
    cin >> p[i];
  }
  

  
  int ans = 0;

  // N個のスイッチ bit 全探索
  for (int bit = 0; bit < (1 << N); bit++) {
    
    // 押された情報の初期化
    vector<int> num(M+1,0);
    
    
    // 押したスイッチごとにつながっている電球のスイッチ回数を+1
    for (int i = 0; i < N; i++) {
      
      if (bit & (1 << i)) {
        for (int j = 0; j < sw[i+1].size(); j++) {
          num[sw[i+1][j]]++;
        }
        
      }
    }

    bool cond = true;

    //　それぞれの電球が点灯するかのチェック
    for (int i = 1; i <= M; i++) {
      if (num[i] % 2 != p[i]) {
        cond = false;
        break;
      }
    }
    
    if (cond) ans++;
    
  }
  
  cout << ans << endl;
  
}