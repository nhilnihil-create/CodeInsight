#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  int m = 0;
  vector<P>ans;
  vector<vector<bool>>data(n,vector<bool>(n,true));
  rep(i,0,n) data[i][i] = false;
  rep(i,0,n/2){
    if(n%2 == 0) data[i][n-i-1] = data[n-i-1][i] = false;
    else data[i][n-i-2] = data[n-i-2][i] = false;
  }
  rep(i,0,n) rep(j,0,n){
    if(data[i][j]){
      m++;
      ans.push_back(P(i+1,j+1));
      data[j][i] = false;
    }
  }
  cout << m << endl;
  rep(i,0,ans.size()) cout << ans[i].first << " " << ans[i].second << endl;
}