#include <bits/stdc++.h>
using namespace std;


int main(){
  int n,m;
  cin >> n >> m ;
  vector<int> k(m),p(m);
  vector<vector<int>> s(m,vector<int>(10));
  for(int i = 0;i<m;i++){
    cin >> k[i];
    for(int j = 0;j<k[i];j++){
      cin >> s[i][j];
    }
  }
  for(int i = 0;i<m;i++)cin >> p[i];

  //処理
  int ans = 0;
  for(int bit = 0; bit < (1<< n); bit ++){
    vector<int> swit(n);
    for(int i=0;i<n;i++){
      if(bit & (1<<i)){
        swit[i] = 1;
      }
    }
    bool check = true;
    for(int i = 0;i < m;i++){
      int cnt = 0;
      for(int j = 0;j < k[i]; j++){
        cnt += swit[s[i][j]-1];
      }
      if(cnt%2 != p[i])check = false;
    }
    if(check)ans++;
  }
  cout << ans << endl;
  return 0;
}