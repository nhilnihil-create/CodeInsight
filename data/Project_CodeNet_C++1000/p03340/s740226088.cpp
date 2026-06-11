#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;

bool ok(vector<int> p,vector<int> q){
  bool res = true;
  rep(i,23){
    if(p.at(i) + q.at(i) == 2){
      res = false;
      break;
    }
  }
  return res;
}
 
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a.at(i);
  vector<vector<int>> b(n,vector<int>(23,0));
  rep(i,n){
    rep(j,23){
      if(a.at(i) >> j & 1) b.at(i).at(j) = 1;
    }
  } 
  
  ll ans = 0;
  int j = -1;
  vector<int> now(23,0);
  rep(i,n){
    while(j < n-1){
      if(ok(now,b.at(j+1))){
        rep(k,23){
          if(b.at(j+1).at(k) == 1) now.at(k) = 1;
        }
        j ++;
      }else{
        break;
      }
    }
    ans += j-i+1;
    rep(k,23){
      if(b.at(i).at(k) == 1) now.at(k) = 0;
    }    
  }
  cout << ans << endl;    

  return 0;
}

