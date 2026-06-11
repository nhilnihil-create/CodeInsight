#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){

  int n,m;
  cin >> n >> m;
  vector<string> res(m,"");
  vector<vector<Pl>> v(n+1);
  rep(i,m){
    int p,y;cin >> p >> y;
    v[p].push_back(make_pair(y,i));
  }
  rep(i,n+1)sort(ALL(v[i]));
  rep(i,n+1){
    int ss = 0;
    int kk = i;
    while(kk)ss++,kk/=10;
    string k = "";
    rep(l,6-ss)k += '0';
    k += to_string(i);
    for(int j = 0;j < v[i].size();j++){
      res[v[i][j].second] += k;
      kk = j+1;
      ss = 0;
      while(kk)ss++,kk/= 10;
      rep(l,6-ss)res[v[i][j].second] += '0';
      res[v[i][j].second] += to_string(j+1);
    }
  }
  rep(i,m)cout << res[i] << endl;

  

  return 0;
}