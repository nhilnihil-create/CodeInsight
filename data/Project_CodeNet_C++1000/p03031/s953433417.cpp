#include <bits/stdc++.h>

using namespace std;

int main() {
  int n,m;
  cin >> n >> m;
  vector<vector<int>> s(m, vector<int>(10, 0));
  for(int i = 0; i < m; i++) {
    int k;
    cin >> k;
    for(int j = 0; j < k; j++) {
      cin >> s.at(i).at(j);
    }
  }

  vector<int> p(m);
  for(int i=0;i<m;i++) cin >> p[i];
  
  int ans=0;
  for (int bit = 0; bit < (1<<n); ++bit) {
      vector<int> S;
      for (int i = 0; i < n; ++i) {
           if (bit & (1<<i)) { // 列挙に i が含まれるか
              S.push_back(i+1);
          }
      }
      int totalon=0;
      for(int i = 0; i < m; i++) {
        int non=0;
        for(int j = 0; j < 10; j++) {
          for(int h = 0; h < S.size(); h++) {
            if(S[h]==s.at(i).at(j)) non++;
          }
        }
        if(non%2==p[i]) totalon++;
      }
      if(totalon==m) ans++;
  }
  cout << ans << endl;
  return 0;
}