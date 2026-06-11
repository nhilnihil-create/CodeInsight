#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

int main() {
  int n,m,q;
  cin>>n>>m>>q;
  vector<vector<int>>c(n+1,vector<int>(n+1));
  vector<int>a(m),b(m);
  rep(i,m){
    cin>>a.at(i)>>b.at(i);
    c.at(a.at(i)).at(b.at(i))++;
  }
  rep(i,n+1){
    rep2(j,1,n+1){
      c.at(i).at(j)+=c.at(i).at(j-1);
    }
  }
  
  rep(i,q){
    int P,Q;
    cin>>P>>Q;
    int ans=0;
    rep2(j,P,Q+1){
      ans+=c.at(j).at(Q)-c.at(j).at(P-1);
    }
    cout<<ans<<endl;
  }
}