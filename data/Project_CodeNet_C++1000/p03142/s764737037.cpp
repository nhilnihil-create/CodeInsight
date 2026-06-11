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
  ll n,m;cin>>n>>m;
  vector<vector<ll>>ed(n),red(n);
  vector<ll>d(n),res(n);
  rep(i,m+n-1){
    ll a,b;cin>>a>>b;
    a--;b--;
    ed[a].push_back(b);
    red[b].push_back(a);
  }
  ll root;
  rep(i,n){
    if(red[i].size()==0)root=i;
  }
  vector<ll>flag(n);
  rep(i,n)flag[i]=red[i].size();
  queue<ll>q;
  q.push(root);
  while(!q.empty()){
    ll v=q.front();q.pop();
    for(auto nv:ed[v] ){
      flag[nv]--;
      if(flag[nv]==0){
        q.push(nv);
        res[nv]=v+1;
      }
    }
  }
  rep(i,n)cout<<res[i]<<endl;



  return 0;

}
