#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define f(i,st,n) for(i=st;i<n;i++)
#define qu queue
#define ps(x) push(x)
#define vec vector
#define ft() front()
#define mst(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define sfl(x) scanf("%lld",&x)
#define pfl(x) printf("%lld\n",x)
#define pf(x) printf("%lld",x)
#define mpr make_pair
#define fs first
#define se second
#define inf LLONG_MAX
#define nnf LLONG_MIN




ll gcd(ll a, ll b) {
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}
ll power(ll x, ll y) {
  ll res = 1;
  while (y > 0) {
    if (y % 2 == 1) {
      res = ((res) * (x));
    }
    x = ((x) * (x));
    y = y / 2;
  }
  return res;
}
ll seg[800005],dp[200005];

 

void update(ll i,ll st,ll end,ll val,ll ind){
    if(st==end){
        
        seg[i]=val;
        dp[ind]=val;
       
    }
    else{
        ll mid=(st+end)/2;
        if(ind>=st&&ind<=mid){
           update(2*i+1,st,mid,val,ind); 
        }
        else{
            update(2*i+2,mid+1,end,val,ind);
        }
        seg[i]=max(seg[2*i+1],seg[2*i+2]);
    }
}
ll query(ll i,ll st,ll end,ll l,ll r){
    if(st>r||end<l){
        return 0;
    }
    if(st>=l&&end<=r){
        return seg[i];
    }
    ll mid=(st+end)/2;
    return max(query(2*i+1,st,mid,l,r),query(2*i+2,mid+1,end,l,r));
}


int main() {

/*#ifndef ONLINE_JUDGE

  freopen("input.txt", "r", stdin);

  freopen("output.txt", "w", stdout);
#endif*/

  ll n,i;
  sfl(n);
  ll h[n],a[n];

  f(i,0,n)sfl(h[i]);
  f(i,0,n)sfl(a[i]);

  f(i,0,n){
    ll x=query(0,0,n,0,h[i]-1);

    if(x+a[i]>dp[h[i]]){
        update(0,0,n,x+a[i],h[i]);
    }
  }
  pfl(query(0,0,n,0,n));


  return 0;




}