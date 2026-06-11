#include<bits/stdc++.h>
//ios::sync_with_stdio(false);
//cin.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plpl;
typedef tuple<ll,ll,ll> tl;
ll mod=1000000007;
ll mod2=998244353;
ll inf=1000000000000000000;
double pi=2*acos(0);
#define rep(i,m,n) for(int i=m;i<n;i++)
#define rrep(i,n,m) for(int i=n;i>=m;i--)
ll lmax(ll a,ll b){
    if(a<b)return b;
    else return a;
}
ll lmin(ll a,ll b){
    if(a<b)return a;
    else return b;
}
int main(){
    ll n;cin>>n;
    vector<double> t(n),v(n);
    double sum[n+1];
  sum[0]=0;
  
    rep(i,0,n){
        cin>>t[i];
        sum[i+1]=sum[i]+t[i];
    }
    rep(i,0,n)cin>>v[i];
  v.insert(v.begin(),0);
    vector<pair<double,int>> w;
  double mi[80001];
  fill(mi,mi+80001,1000000000);
  rep(i,0,sum[n]*2+1){
    mi[i]=i/2.0;
  }
  rrep(i,sum[n]*2,0){
    double r=(sum[n]*2-i)/2.0;
    if(mi[i]>r){
      mi[i]=r;
    }
    else break;
  }
    rep(i,1,n+1){
      w.push_back(make_pair(v[i],i));
    }
  sort(w.begin(),w.end());
  rep(i,0,n){
    double now=w[i].first;int num=w[i].second;
    double ta=sum[num]-t[num-1];
    double tb=sum[num];
    rep(j,2*ta+1,2*tb)mi[j]=min(mi[j],v[num]);
    rrep(j,2*ta,0){
      double r=v[num]+(2*ta-j)/2.0;
      if(mi[j]>r)mi[j]=r;
      else break;
    }
    rep(j,2*tb,sum[n]*2+1){
      double r=v[num]+(j-2*tb)/2.0;
      if(mi[j]>r)mi[j]=r;
      else break;
    }
  }
  double ans=0;
  rep(i,0,sum[n]*2){
    ans+=0.25*(mi[i]+mi[i+1]);
  }
  cout<<fixed<<setprecision(12)<<ans<<endl;
}