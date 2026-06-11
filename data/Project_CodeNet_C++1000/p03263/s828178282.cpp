#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) (a).begin(),(a).end()
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll h,w;cin>>h>>w;
  vector<lvector> A(h,lvector(w,0));rep(i,h)rep(j,w) cin>>A[i][j];
  vector<lvector> ans;
  ll xpos=0,ypos=0,xold=0,yold=0,sign=1;
  for(ll dy=0;dy<h;++dy) {
    ypos=dy;
    if(xold==w-1) {sign=-1;xpos++;}else {sign=1;xpos--;}
    for(ll dx=0;dx<w;++dx) {
      xpos+=sign;
      if(!(xpos==xold&&ypos==yold)&&A[yold][xold]%2==1) {
        A[yold][xold]--;A[ypos][xpos]++;
        ans.emplace_back(lvector{yold+1,xold+1,ypos+1,xpos+1});
      }
      xold=xpos,yold=ypos;
    }
  }
  print(ans.size());
  for(lvector v:ans) {
    rep(i,3) cout<<v[i]<<" ";
    cout<<v[3]<<endl;
  }
  return 0;
}
