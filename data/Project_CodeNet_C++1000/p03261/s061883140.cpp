#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;
const int ny[4] = {-1,1,0,0}, nx[4] = {0,0,-1,1};
int sy,sx,gy,gx;

int main(){
  int n; cin >> n;
  vector<string> w(n);
  rep(i,n) cin >> w[i];
  map<string,int> mp;
  mp[w[0]]++;
  bool flg = true;
  for(int i = 1; i < n; i++){
    mp[w[i]]++;
    if(mp[w[i]] == 2){
      flg = false;
    }
    if(w[i-1][w[i-1].size()-1] != w[i][0]){
      flg = false;
    }
  }
  if(flg) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
