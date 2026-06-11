#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n; cin >>n;
  vector<int> d(n);
  map<int, int> mpd;
  rep(i,n){
    cin >>d[i];
    mpd[d[i]]++;
  }
  int m; cin >>m;
  vector<int> t(m);
  rep(i,m) cin >>t[i];
  bool can = true;
  for(int x : t){
    if(mpd[x]==0) can = false;
    else mpd[x]--;
    if(!can) break;
  }
  if(can) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0; 
}