#include <iostream>
#include <vector>
  
using namespace std;

vector<vector<int>> s;

int main(){
  int n, m;
  cin >> n >> m;

  vector<int> k(m), p(m);
  s.resize(m);
  for(int i = 0; i < m; i++) {
    cin >> k[i];
    s[i].resize(k[i]);
    for(int j = 0; j < k[i]; j++) {
      cin >> s[i][j];
    }
  }
  for(int i = 0; i < m; i++) cin >> p[i];

  int cnt = 0;
  for(int bit = 0; bit < (1 << n); bit++) { // 全スイッチの組み合わせ
    bool all_light = true;
    for(int bulb = 0; bulb < m; bulb++) { // 全電球が点灯するか確認
      bool light = true;
      int sw_cnt = 0;
      for(int sw = 0; sw < k[bulb]; sw++) { // 電球の点灯する条件を確認
        if(bit & (1 << s[bulb][sw]-1)) {
          sw_cnt++;
        }
      }
      //cout << bit << " " << bulb << " "  << sw_cnt << endl;
      if(sw_cnt%2 != p[bulb]) {
        all_light = false;
      }
    }
    if(all_light) {
      cnt++;
    }
  }

  cout << cnt << endl;
    
  return 0;
}
