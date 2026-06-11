#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin >> n >> m; 
  int k[m];
  vector<vector<int>> s(m);
  for(int i=0;i<m;i++){
    cin >> k[i];
    s[i].resize(k[i]);
    for(int j=0;j<k[i];j++){
      cin >> s[i][j];
      --s[i][j];
    }
  }
  int ans=0;
  vector<int> p(m);
  for(int i=0;i<m;i++)cin >> p[i];
  for(int i=0;i<(1<<n);i++){
    bool ok=true;
    for(int j=0;j<m;j++){
      int cnt=0;
      for(auto it:s[j]){
        if(i&(1<<it))cnt++;
      }
      cnt%=2;
      if(cnt!=p[j])ok=false;
    }
    if(ok)ans++;
  }
  cout << ans << endl;
}
      