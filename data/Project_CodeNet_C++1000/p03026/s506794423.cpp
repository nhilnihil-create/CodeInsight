#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>
#include <stack>
#include <cstdint>



#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rrep(i, n) for(ll i = (ll)(n-1); i >= 0; i--)
#define repi(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rrepi(i,a,b) for(ll i=(ll)(b);i>=(ll)(a);i--)

#define all(x) (x).begin(),(x).end()

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;


template <class Monoid>
class SegmentTree
{
public:
  using Func = function<Monoid(Monoid, Monoid)>;
  const Func F;
  const Monoid M1;
  int sz;
  vector<Monoid> seg;

  SegmentTree(int n,const Func fu, const Monoid &m1): F(fu) , M1(m1) {init(n);}
  void init(int n)
  {
      sz= 1;
      while (sz <= n) sz *= 2;
      seg.assign(sz * 2, M1);
  }
  void update(int k,const Monoid &x)
  {
    k+=sz;
    seg[k]=x;
    while(k>>=1)
    {
      seg[k]=F(seg[k*2],seg[k*2+1]);
    }
  }
  Monoid query(int l,int r)
  {
    Monoid L=M1,R=M1;
    l+=sz;r+=sz;
    for(;l<r;l>>=1,r>>=1)
    {
      if(l&1)L=F(L,seg[l++]);
      if(r&1)R=F(seg[--r],R);
    }
    return F(L,R);
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;cin>>n;
  vector<vector<ll>>ed(n);
  rep(i,n-1){
    ll a,b;cin>>a>>b;
    a--;b--;
    ed[a].push_back(b);
    ed[b].push_back(a);
  }
  using pll=pair<ll,ll>;
  auto f=[](pll a,pll b){return min(a,b);};
  SegmentTree<pll>st(n,f,{1e9,1e9});
  rep(i,n){
    st.update(i,{ed[i].size(),i});
  }
  vector<ll>c(n);
  rep(i,n)cin>>c[i];
  sort(all(c));
  vector<ll>res(n,-1);
  ll m=0;
  ll i=0;
  while(1){
    auto tp=st.query(0,n);
    ll id=tp.second;
    st.update(id,{1e9,n});
    res[id]=c[i++];
    if(i==n)break;
    for(auto nn:ed[id]){
      auto ttp=st.query(nn,nn+1);
      if(res[nn]==-1)m+=c[i-1];
      st.update(nn,{ttp.first-1,ttp.second});
    }
    ed[id].assign(ed[id].size(),-1);
  }
  cout<<m<<endl;
  rep(i,n)cout<<res[i]<<" ";
  cout<<endl;


  return 0;

}
