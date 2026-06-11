#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, cnt = 0;
  scanf("%d %d", &n, &m);
  vector<vector<int>> v(m);
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    for(int j = 0; j < k; j++) {
      int x;
      cin >> x;
      v[i].push_back(x - 1);//電球番号は1始まりなのでずらすよ
    }
  }
  vector<int> p(m);
  for(int i = 0; i < m; i++) cin >> p[i];
  
  
  for (int tmp = 0; tmp < (1 << n); tmp++) {
    bitset<10> s(tmp);
    bool all = true;
    for(int i = 0; i < m; i++) {
      int on = 0;
      for(int j = 0; j < v[i].size(); j++) {
        if(s.test(v[i][j])) on++;
      }
      if(on % 2 != p[i]) {
        all = false;
        break;
      }
    }
    if(all) cnt++;
  }
  cout << cnt;
}