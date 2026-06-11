#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>
#define int ll

main(){
  int h,w,d;
  cin>>h>>w>>d;
  vector<P> p(h*w); 
  rep(i,h)rep(j,w){
    int a;
    cin>>a;
    a--;
    p[a]=make_pair(i,j);
  }
  vector<int> r[d];
  rep(s,d){
    r[s].push_back(0);
    for(int i=1; i*d+s<h*w; i++){
      int pi,pj,ni,nj;
      tie(pi,pj)=p[(i-1)*d+s];
      tie(ni,nj)=p[i*d+s];
      r[s].push_back(r[s][r[s].size()-1]+abs(ni-pi)+abs(nj-pj));
    }
  }
  int q;
  cin>>q;
  rep(i,q){
    int L,R;
    cin>>L>>R;
    L--; R--;
    cout<<r[R%d][R/d]-r[L%d][L/d]<<endl;;
  }
}