#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define fix20 cout << fixed << setprecision(20);
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define MOD 1000000007

int dic[10] = {0,2,5,5,4,5,6,3,7,6};

bool compare(vi atk,int j,vi def){
  int m = atk.size();
  atk.at(j)++;
  int a = 0;
  int d = 0;
  rep(i,m){
    a += atk.at(i);
    d += def.at(i);
  }
  if(a > d) return true;
  else if(a < d) return false;
  
  rep(i,m){
    if(atk.at(i) == def.at(i)) continue;
    if(atk.at(i) > def.at(i)) return true;
    else return false;
  }
}

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> a(m);
  rep(i,m) cin >> a.at(i);
  sort(a.begin(),a.end(),greater<int>());
  vector<vector<int>> dp(n+1,vector<int>(m,0));
  //rep(i,m) dp.at(0).at(i) = 0;
  vector<bool> flag(n+1,false);
  flag.at(0) = true;
  rep(i,n){
    //if(dp.at(i).at(0) == -1) continue;
    if(!flag.at(i)) continue;
    rep(j,m){
      int num = a.at(j);
      int match = dic[num];
      if(i+match > n) continue;
      flag.at(i+match) = true;
      if(compare(dp.at(i),j,dp.at(i+match))){
        rep(k,m){
          if(k == j) dp.at(i+match).at(k) = dp.at(i).at(k) + 1;
          else dp.at(i+match).at(k) = dp.at(i).at(k);
        }
      }
    }
  }
  int cnt = 0;
  rep(i,m){
    rep(j,dp.at(n).at(i)){
      cout << a.at(i);
      cnt += dic[a.at(i)];
    }
  }
  cout << endl;
  //cout << cnt << endl;
  /*rep(i,n+1){
    cout << i << ":";
    rep(j,m) cout << dp.at(i).at(j);
    cout << endl;
  }*/
}