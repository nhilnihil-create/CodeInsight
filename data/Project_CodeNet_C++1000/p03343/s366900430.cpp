#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0,i##_max=(N);i<i##_max;++i)
#define repp(i,l,r) for(int i=(l),i##_max=(r);i<i##_max;++i)
#define per(i,N) for(int i=(N)-1;i>=0;--i)
#define perr(i,l,r) for(int i=r-1,i##_min(l);i>=i##_min;--i)
#define all(arr) (arr).begin(), (arr).end()
#define SP << " " <<
#define SPF << " "
#define SPEEDUP cin.tie(0);ios::sync_with_stdio(false);
#define MAX_I INT_MAX //1e9
#define MIN_I INT_MIN //-1e9
#define MAX_UI UINT_MAX //1e9
#define MAX_LL LLONG_MAX //1e18
#define MIN_LL LLONG_MIN //-1e18
#define MAX_ULL ULLONG_MAX //1e19
  typedef long long ll;
  typedef pair<int,int> PII;
  typedef pair<char,char> PCC;
  typedef pair<ll,ll> PLL;
  typedef pair<char,int> PCI;
  typedef pair<int,char> PIC;
  typedef pair<ll,int> PLI;
  typedef pair<int,ll> PIL; 
  typedef pair<ll,char> PLC; 
  typedef pair<char,ll> PCL; 

inline void YesNo(bool b){ cout << (b?"Yes" : "No") << endl;}
inline void YESNO(bool b){ cout << (b?"YES" : "NO") << endl;}
inline void Yay(bool b){ cout << (b?"Yay!" : ":(") << endl;}

template< typename Monoid >
struct SegmentTree{
  using F = function< Monoid(Monoid, Monoid) >;
  
  int sz;
  vector< Monoid > seg;

  const F f;
  const Monoid M1;

  //SegmentTree(n,f,M1):サイズnの初期化，fは2つの苦汗の要素をマージする二項演算，M1はモノイドの単位元
  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1){
    sz = 1;
    while(sz < n) sz<<=1;
    seg.assign(2*sz,M1);
  }

  //set(k,x):k番目の要素にxを代入
  void set(int k, const Monoid &x){
    seg[k+sz] = x;

  }
  
  //build():segTreeの構築
  void build(){
    for(int k = sz-1; k>0; --k){
      seg[k] = f(seg[2*k+0], seg[2*k+1]);
    }
  }

  //update(k,x):k番目の要素をxに変更
  void update(int k, const Monoid &x){
    k += sz;
    seg[k] = x;
    while(k>>=1) seg[k] = f(seg[2*k+0],seg[2*k+1]);
  }

  //区間[a,b)のMonoidを計算
  Monoid query(int a, int b){
    Monoid L = M1, R = M1;
    for(a += sz, b+=sz; a < b; a>>=1, b>>=1){
      if(a&1) L = f(L,seg[a++]);
      if(b&1) R = f(seg[--b],R);
    }
    return f(L,R);
  }

  //operator[k]:k番目の要素を返す
  Monoid operator[](const int &k) const{
    return seg[k+sz];
  }
};

int main(void){
  SPEEDUP
  cout << setprecision(15);
  int N,K,Q;cin >> N >> K >> Q;
  vector<int> v(N);
  //範囲の最小値を返すsegTree
  set<int> st;
  rep(i,N){
    cin >> v[i];
    st.insert(v[i]);
  }
  int ans = MAX_I;
  for(const int& s:st){
    vector<int> w;
    vector<int> del;
    w.push_back(-1);
    rep(i,N)if(v[i]<s)w.push_back(i);
    w.push_back(N);
    rep(x,w.size()-1){
      if(w[x+1]-w[x]-1<K)continue;
      priority_queue<int, vector<int>, greater<int> >pq;
      repp(i,w[x]+1,w[x+1]) pq.push(v[i]);
      while(pq.size()>=K){
        del.push_back(pq.top());
        pq.pop();
      }
    }
    if(del.size()<Q)continue;
    sort(all(del));
    ans = min(ans, del[Q-1]-s);
  }
  cout << ans << endl;
  return 0;
}
