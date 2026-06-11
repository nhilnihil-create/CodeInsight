#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n,t; cin >> n >> t;
  vector<pair<int,int>> ct(n);
  rep(i,n){
    int cost,time; cin >> cost >> time;
    ct[i] = make_pair(cost,time);
  }
  sort(ct.begin(),ct.end());
  int ans=-1;
  rep(i,n){
    if(ct[i].second<=t){
      ans = ct[i].first;
      break;
    }
  }
  if(ans == -1) cout << "TLE" << endl;
  else cout << ans << endl;
  
  return 0;
}
