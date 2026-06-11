#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<endl;
}

template <class T>
void cout_vec2(const vector<vector<T>> &vec){
  rep(i,vec.size()){
    rep(j,vec[i].size()){
      cout<<vec[i][j]<<' ';
    }
    cout<<endl;
  }
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;
const ll inf=1e15;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  vector<int> t(n),v(n);
  int T=0;
  rep(i,n){
    cin>>t[i];
    T+=t[i];
  }
  rep(i,n) cin>>v[i];
  double now=0;
  map<double,double> maxv;
  maxv[now]=0;
  now+=0.5;
  double now_t=0;
  rep(i,n){
    now_t+=t[i];
    while(now<now_t){
      maxv[now]=v[i];
      now+=0.5;
    }
    if(i<n-1){
      maxv[now]=min(v[i],v[i+1]);
      now+=0.5;
    }
  }
  maxv[T]=0;
  now=0.5;
  while(now!=T+0.5){
    maxv[now]=min(maxv[now],maxv[now-0.5]+0.5);
    now+=0.5;
  }
  now=T-0.5;
  while(now!=-0.5){
    maxv[now]=min(maxv[now],maxv[now+0.5]+0.5);
    now-=0.5;
  }
  double ans=0;
  now=0;
  while(now!=T){
    ans+=(maxv[now]+maxv[now+0.5])*0.5*0.5;
    now+=0.5;
  }
  cout<<setprecision(10)<<ans<<endl;
}