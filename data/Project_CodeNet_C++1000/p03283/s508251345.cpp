#include<bits/stdc++.h>
using namespace std;

int x[510][510],rui[510][510];

int main(){
  int n,m,q;
  cin >> n >> m >> q;
  //vector<vector<int>> x(n,vector<int>(n+1,0));
  for(int i=0;i<m;++i){
    int l,r;
    cin >> l >> r;
    x[l][r]++;
  }
  //vector<vector<int>> rui(n+2,vector<int>(n+2,0));
  for(int i=1;i<=n;++i){
    for(int j=1;j<=n;++j){
      rui[i][j]=rui[i][j-1]+x[i][j];
    }
  }
  vector<int> ans;
  for(int i=0;i<q;++i){
    int l,r;
    cin >> l >> r;
    int cal=0;
    for(int j=l;j<=r;++j){
      cal+=rui[j][r]-rui[j][l-1];
    }
    ans.push_back(cal);
  }
  int k=ans.size();
  for(int i=0;i<k;++i) cout << ans[i] << endl;
  return 0;
}
