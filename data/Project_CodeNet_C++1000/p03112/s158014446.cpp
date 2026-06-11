#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int a,b,q;
  cin>>a>>b>>q;
  ll s[a];
  ll is[a];
  ll t[b];
  ll it[b];
  ll x[q];
  rep(i,0,a){
    cin>>s[i];
    is[i]=-s[i];
  }
  rep(i,0,b){
    cin>>t[i];
    it[i]=-t[i];
  }
  rep(i,0,q) cin>>x[i];
  sort(s,s+a);
  sort(is,is+a);
  sort(t,t+b);
  sort(it,it+b);
  rep(i,0,q){
    ll l=1e15;
    ll r=1e15;
    int c=lower_bound(s,s+a,x[i])-s;
    int d=lower_bound(t,t+b,x[i])-t;
    if(c<a && d<b){
      if(s[c]<t[d]){
        int e=lower_bound(t,t+b,s[c])-t;
        if(e!=b) l=min(l,(s[c]-x[i])+(t[e]-s[c]));
        if(e!=0) l=min(l,(s[c]-x[i])+(s[c]-t[e-1]));
      }
      else{
        int e=lower_bound(s,s+a,t[d])-s;
        if(e!=a) l=min(l,(t[d]-x[i])+(s[e]-t[d]));
        if(e!=0) l=min(l,(t[d]-x[i])+(t[d]-s[e-1]));
      }
    }
    else if(c==a && d<b){
      int e=lower_bound(s,s+a,t[d])-s;
      if(e!=a) l=min(l,(t[d]-x[i])+(s[e]-t[d]));
      if(e!=0) l=min(l,(t[d]-x[i])+(t[d]-s[e-1]));
    }
    else if(c<a && d==b){
      int e=lower_bound(t,t+b,s[c])-t;
      if(e!=b) l=min(l,(s[c]-x[i])+(t[e]-s[c]));
      if(e!=0) l=min(l,(s[c]-x[i])+(s[c]-t[e-1]));
    }
    
    c--;
    d--;
    if(c>=0 && d>=0){
      if(s[c]>t[d]){
        int e=lower_bound(t,t+b,s[c])-t;
        if(e!=b) r=min(r,(x[i]-s[c])+(t[e]-s[c]));
        if(e!=0) r=min(r,(x[i]-s[c])+(s[c]-t[e-1]));
      }
      else{
        int e=lower_bound(s,s+a,t[d])-s;
        if(e!=a) r=min(r,(x[i]-t[d])+(s[e]-t[d]));
        if(e!=0) r=min(r,(x[i]-t[d])+(t[d]-s[e-1]));
      }
    }
    else if(c<0 && d>=0){
      int e=lower_bound(s,s+a,t[d])-s;
      if(e!=a) r=min(r,(x[i]-t[d])+(s[e]-t[d]));
      if(e!=0) r=min(r,(x[i]-t[d])+(t[d]-s[e-1]));
    }
    else if(c>=0 && d<0){
      int e=lower_bound(t,t+b,s[c])-t;
      if(e!=b) r=min(r,(x[i]-s[c])+(t[e]-s[c]));
      if(e!=0) r=min(r,(x[i]-s[c])+(s[c]-t[e-1]));
    }
    
    cout<<min(l,r)<<endl;
  }
}