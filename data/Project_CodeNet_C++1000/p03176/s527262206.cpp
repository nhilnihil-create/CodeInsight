#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// ll inf=(ll)1e18;
ll seg[800000]={0},h[200000],b[200000];

ll ans(ll l,ll r,ll tl,ll tr,ll v){
  if(l>r)return 0;
  if(tl==l&&tr==r)return seg[v];
  ll tm=tl+(tr-tl)/2;
  return max(ans(l,min(tm,r),tl,tm,2*v) ,ans(max(tm+1,l),r,tm+1,tr,2*v+1) );
}

void update(ll v,ll tl,ll tr,ll pos,ll val){
  if(tl==tr) {seg[v]=max(seg[v],val); return ;}
  ll tm= tl+(tr-tl)/2;
  if(pos<=tm) update(2*v,tl , tm, pos,val);
  else  update(2*v+1, tm+1,tr, pos,val);
  seg[v]= max({seg[v],seg[2*v] , seg[2*v+1]});
}

int main(){
  ll i,n,x,y;
  cin>>n;
  for(i=0;i<n;i++)cin>>h[i];
  for(i=0;i<n;i++)cin>>b[i];
  ll answer=0;
  for(i=0;i<n;i++){
    ll k=ans( 0,h[i]-1,0,n-1,1);
    answer=max(answer,k+b[i]);
    update(1,0,n-1,h[i]-1, k+b[i]);
  }
   cout<<answer;
}