#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n,c;
  cin >> n >> c;
  vector<vector<int>>data(c,vector<int>(1e5+1,0));
  rep(i,0,n){
    int s,t,cc;
    cin >> s >> t >> cc;
    cc--;
    data[cc][s]++;
    data[cc][t]--;
  }
  vector<vector<P>>table(c);
  rep(i,0,c){
    int s;
    rep(j,0,1e5+1){
      if(data[i][j] == 1) s = j;
      if(data[i][j] == -1) table[i].push_back(P(s,j));
    }
  }
  vector<int>imos(1e5+1);
  rep(i,0,c) rep(j,0,table[i].size()){
    //cout << i << " " << table[i][j].first << " " << table[i][j].second << endl;
    imos[table[i][j].first]++;
    if(table[i][j].second+1 <= 1e5) imos[table[i][j].second+1]--;
  }
  int ans = 0,sum = 0;
  rep(i,1,1e5+1){
    sum += imos[i];
    ans = max(ans,sum);
    //cout << sum << endl;
    //cout << imos[i] << endl;
  }
  cout << ans << endl;
}