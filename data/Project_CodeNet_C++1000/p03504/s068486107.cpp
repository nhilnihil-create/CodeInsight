#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <fstream>
#include <chrono>
#include <random>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) ((int)(x).size())
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;

int main(){
  int n, C; cin >> n >> C;
  vector<pair<int,pair<int,int>>> cst;
  vector<vector<int>> CT(C,vector<int>(100010, 0));
  int s, t, c;
  rep(i,n) {
    cin >> s >> t >> c;
    CT[c-1][s]++;
    CT[c-1][t+1]--;
  };
  rep(i,C){
    rep(j,100010){
      if(j==0) continue;
      CT[i][j] = CT[i][j-1]+CT[i][j];
    }
    //rep(j,10) {cout << CT[i][j] <<" "; cout << endl; }
    int st=0;
    rep(j,100010){
      if(st==0 && CT[i][j]==1) st = j;
      if(st!=0 && CT[i][j]==0) {
        cst.pb({i, {st, j-1}});
        st = 0;
      }
    }
  }
  for(auto x:cst) {
    //cout << x.first << " " << x.second.first << " " << x.second.second << endl;
  }
  vector<int> time(100010, 0);
  rep(i,sz(cst)){
    time[cst[i].second.first-1]++;
    time[cst[i].second.second]--;
  }
  rep(i,sz(time)){
    if(i==0) continue;
    time[i] = time[i-1]+time[i];
  }
  int ans = 0;
  rep(i,sz(time)){
    ans = max(ans, time[i]);
  }
  cout << ans << endl;
  return 0;
}
