#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
vector<ll> node[200005];
bool used[200005];
P d1(ll pos){
  P res=P(0,pos);
  for(int i=0;i<node[pos].size();i++){
    int to=node[pos][i];
    if(used[to]) continue;
    used[to]=true;
    P dans=d1(to);
    if(dans>res) res=dans;
  }
  res.first++;
  return res;
}
int main(){
  vector<ll> lsum,rsum,l;
  vector<P> r;
  ll n;
  cin>>n;
  vector<ll> in_l;
  for(int i=0;i<n;i++){
    ll a,b;
    cin>>a>>b;
    in_l.push_back(b);
    r.push_back(P(a,i));
  }
  ll ls=0,rs=n;
  lsum.push_back(0);
  sort(r.begin(),r.end(),greater<P>());
  rsum.push_back(0);
  for(int i=0;i<r.size();i++) rsum.push_back(rsum[i]+r[i].first);
  priority_queue<ll,vector<ll>,greater<ll>> pque;
  ll ans=0;
  for(ll border=-100005;border<=100005;border++){
    if(rs>0){
      while(r[rs-1].first<border&&rs>0){
        pque.push(in_l[r[rs-1].second]);
        rs--;
        r.pop_back();
      }
    }
    while(!pque.empty()&&pque.top()<=border){
      l.push_back(pque.top());
      lsum.push_back(lsum[ls]+pque.top());
      pque.pop();
      ls++;
    }
    ll max_v=min(ls,rs)+1;
    ll kans=abs(border);
    ll lkb=min(ls,max_v),rkb=min(rs,max_v);
    if(border<0){
      if(lkb<=rkb) rkb=lkb-1;
    }
    if(border>0){
      if(lkb>=rkb) lkb=rkb-1;
    }
    if(lkb<0||rkb<0) continue;
    kans+=(-1*lsum[lkb]+border*lkb);
    kans+=rsum[rkb]-border*rkb;
    kans*=2;
    ans=max(ans,kans);
  }
  cout<<ans<<endl;
}
