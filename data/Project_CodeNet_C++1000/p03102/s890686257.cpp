#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll  = long long;
using v   = vector<int>;
using vv  = vector<v>;
using P   = pair<int,int>;
using vp  = vector<P>;
using vvp = vector<vp>;

int main(){
    int n,m,c;
    cin>>n>>m>>c;
  
  v b(m);
  rep(i,m)cin>>b[i];
  vv a(n, v (m));
  rep(i,n)rep(j,m)cin>>a[i][j];
  
  int ans = 0;
  
  rep(i,n){
    int point = c;
    rep(j,m)point += a[i][j]*b[j];
    if(point>0)ans++;
  }
    cout << ans << endl;
    
    return 0;
}