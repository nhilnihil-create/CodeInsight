#include <bits/stdc++.h>
#define rep(var,cnt) for(int (var)=0; (var)<(int)(cnt); ++(var))
#define REP(var,init,cnt) for(int (var)=(init); (var)<(cnt); ++(var))
#define ran(var,vec) for(auto &(var):(vec))
#define all(v) (v).begin(),(v).end()
#define TF(flag) (flag)?1:0
#define fi first
#define se second
#define debug if(DEBUG)
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pi = pair<int,int>;

template<typename T>
using vec = vector<T>;
template<typename T>
using mat = vector<vec<T>>;

template<typename T1,typename T2>
ostream &operator<<(ostream &os, const pair<T1,T2> &p){
  os<<"P("<<p.first<<", "<<p.second<<") ";
  return os;
}

template<typename T1,typename T2>
istream &operator>>(istream &is, pair<T1,T2> &p){
  is>>p.first>>p.second;
  return is;
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v){
  for(int i=0; i<(int)v.size(); ++i){
    os<<v[i]<<(i+1!=v.size()?" ":"");
  }
  return os;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &v){
  for(T &in:v) is>>in;
  return is;
}

bool DEBUG=true;

int main(){
  int N; cin>>N;
  vec<int> A(N); cin>>A;
  vec<ll> s(N+1,0);
  rep(i,N) s[i+1]=s[i]+A[i];
  
  ll ans=LLONG_MAX;
  int l=1,r=3;
  for(int c=2; c<N-1; ++c){
    valarray<ll> sum(4);
    while(l+1<c&&abs(2*s[l]-s[c])>abs(2*s[l+1]-s[c])) ++l;
    while(r+1<N&&abs(2*s[r]-s[c]-s[N])>abs(2*s[r+1]-s[c]-s[N])) ++r;
    sum[0]=s[l]     ,sum[1]=s[c]-s[l];
    sum[2]=s[r]-s[c],sum[3]=s[N]-s[r];
    ans=min(ans,sum.max()-sum.min());
    if(c+1==r) ++r;
  }
  cout<<ans;
}