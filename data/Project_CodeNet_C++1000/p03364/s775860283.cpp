#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;


int main(){
  vector<string> table(305);
  int n;cin >> n;
  rep(i,n) cin >> table[i];
  int ans = 0;
  rep(t,n){
    if(t > 0){ 
      rep(i,n){
        table[n-i] = table[n-1-i];
      }
      table[0] = table[n];
    }
    bool flag = true;
    rep(i,n)rep(j,n){
      if(table[i][j] != table[j][i]){
        flag = false;
        break;
      }
    }
    if(flag) ans += n;
  }

  cout << ans << endl;
}