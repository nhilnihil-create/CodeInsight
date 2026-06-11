#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<int> v(n),c(n);
  rep(i,n) cin >> v[i];
  rep(i,n) cin >> c[i];
  vector<tuple<double,int,int,int>> vc;  
  rep(i,n){
    double a = (double)v[i]/(double)c[i];
    vc.emplace_back(a,i,v[i],c[i]);
  }

  sort(vc.begin(),vc.end());
  reverse(vc.begin(),vc.end());

  int ans=0;
  int x = 0,y = 0;
  rep(i,n){
    x+=get<2>(vc[i]);
    y+=get<3>(vc[i]);
    ans = max(x-y,ans);
  }

  cout << ans << endl;
  
  return 0;
}
