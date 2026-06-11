#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using datas=pair<ll,ll>;
using ddatas=pair<double,double>;
using tdata=pair<ll,datas>;
using vec=vector<ll>;
using mat=vector<vec>;
using pvec=vector<datas>;
using pmat=vector<pvec>;
#define For(i,a,b) for(i=a;i<(ll)b;i++)
#define bFor(i,a,b) for(i=a;i>=(ll)b;i--)
#define rep(i,N) For(i,0,N)
#define rep1(i,N) For(i,1,N)
#define brep(i,N) bFor(i,N-1,0)
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define vsort(v) sort(all(v))
#define vrsort(v) sort(allr(v))
#define endl "\n"
#define pb push_back
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?" ":"")<<outi;f=1;}cout<<endl;}while(0)
const ll mod=998244353;
const ll inf=1LL<<60;
const double PI = acos(-1);
const double eps = 1e-9;
template<class T> inline bool chmax(T& a,T b){bool x=a<b;if(x)a=b;return x;} 
template<class T> inline bool chmin(T& a,T b){bool x=a>b;if(x)a=b;return x;} 

void startupcpp(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
}

double distance(ddatas& x,ddatas& y){
  double a=x.first-y.first,b=x.second-y.second;
  return sqrt(a*a+b*b);
}

ll modinv(ll a) {
  ll b=mod,u=1,v=0,t;
  while(b){
    t=a/b;
    a-=t*b; swap(a,b);
    u-=t*v; swap(u,v);
  }
  return (u+mod)%mod;
}

ll moddevide(ll a,ll b){return (a*modinv(b))%mod;}

vec modncrlistp,modncrlistm;

ll modncr(ll n,ll r){
  ll i,size=modncrlistp.size();
  if(size<=n){
    modncrlistp.resize(n+1);
    modncrlistm.resize(n+1);
    if(!size){
      modncrlistp[0]=modncrlistm[0]=1;
      size++;
    }
    For(i,size,n+1){
      modncrlistp[i]=modncrlistp[i-1]*i%mod;
      modncrlistm[i]=modinv(modncrlistp[i]);
    }
  }
  return modncrlistp[n]*modncrlistm[r]%mod*modncrlistm[n-r]%mod;
}

ll modpow(ll a,ll n){
  ll res=1;
  while(n){
    if(n&1)res=res*a%mod;
    a=a*a%mod;
    n>>=1;
  }
  return res;
}

ll gcd(ll a,ll b){if(!b)return a;return (a%b==0)?b:gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

ll countdigits(ll n){
  ll ans=0;
  while(n){n/=10;ans++;}
  return ans;
}

ll sumdigits(ll n){
  ll ans=0;
  while(n){ans+=n%10;n/=10;}
  return ans;
}

struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;

public:
  LazySegmentTree(vector<ll> v) {
      int sz = (int)v.size();
      n = 1; while(n < sz) n *= 2;
      node.resize(2*n-1);
      lazy.resize(2*n-1,inf);

      for(int i=0; i<sz; i++) node[i+n-1] = v[i];
      for(int i=n-2; i>=0; i--) node[i] = min(node[i*2+1],node[i*2+2]);
  }
  // k 番目のノードについて遅延評価を行う
  void eval(int k, int l, int r) {
    // 遅延配列が空でない場合、自ノード及び子ノードへの
    // 値の伝播が起こる
    if(lazy[k] != inf) {
      node[k] =min(node[k],lazy[k]);
      // 最下段かどうかのチェックをしよう
      // 子ノードは親ノードの 1/2 の範囲であるため、
      // 伝播させるときは半分にする
      if(r - l > 1) {
        lazy[2*k+1]=min(lazy[2*k+1],lazy[k]);
        lazy[2*k+2]=min(lazy[2*k+2],lazy[k]);
      }
      // 伝播が終わったので、自ノードの遅延配列を空にする
      lazy[k] = inf;
    }
  }

  void add(int a, int b, ll x, int k, int l, int r) {
    if(r < 0) r = n;

    // k 番目のノードに対して遅延評価を行う
    eval(k, l, r);

    // 範囲外なら何もしない
    if(b <= l || r <= a) return;

    // 完全に被覆しているならば、遅延配列に値を入れた後に評価
    if(a <= l && r <= b) {
      lazy[k] =x;
      eval(k, l, r);
    }

    // そうでないならば、子ノードの値を再帰的に計算して、
    // 計算済みの値をもらってくる
    else {
      add(a, b, x, 2*k+1, l, (l+r)/2);
      add(a, b, x, 2*k+2, (l+r)/2, r);
      node[k] =min(node[2*k+1],node[2*k+2]);
    }
  }
  void update(int a, int b, ll x){
    add(a,b,x,0,0,-1);
  }
  //[a,b)の最小値を取得
  ll getsum(int a, int b, int k, int l, int r) {
    if(r < 0) r = n;
    if(b <= l || r <= a) return inf;

    // 関数が呼び出されたら評価！
    eval(k, l, r);
    if(a <= l && r <= b) return node[k];
    ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
    ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
    return min(vl,vr);
  }
  ll get(int a,int b){
    return getsum(a,b,0,0,-1);
  }
};

int main(){
  ll i,N,M=30001,cnt=0;
  cin>>N;
  if(N<8){
    switch(N){
      case 3:
        cout<<"2 5 63"<<endl;
      break;
      case 4:
        cout<<"2 5 20 63"<<endl;
      break;
      case 5:
        cout<<"2 3 4 6 9"<<endl;
      break;
      case 6:
        cout<<"2 3 4 6 9 12"<<endl;
      break;
      case 7:
        cout<<"2 3 4 6 8 9 10"<<endl;
      break;
    }
    return 0;
  }
  vec ans(N);
  switch(N%8){
    case 0:
      rep1(i,M){
        if(i%2==0||i%3==0)ans[cnt++]=i;
        if(cnt==N)break;
      }
    break;
    case 1:
      rep1(i,M){
        if(i%2==0||i%3==0)ans[cnt++]=i;
        if(cnt==N)break;
      }
      ans[--cnt]+=4;
    break;
    case 2:
      rep1(i,M){
        if(i%2==0||i%3==0)ans[cnt++]=i;
        if(cnt==N)break;
      }
      ans[--cnt]+=9;
      ans[--cnt]+=4;
    break;
    case 3:
      rep1(i,M){
        if(i%2==0||i%3==0)ans[cnt++]=i;
        if(cnt==N)break;
      }
      ans[cnt-2]+=3;
    break;
    case 4:
      rep1(i,M){
        if(i%2==0||i%3==0)ans[cnt++]=i;
        if(cnt==N)break;
      }
      ans[cnt-3]+=9;
    break;
    case 5:
      rep1(i,M){
        if(i%2==0||i%3==0)ans[cnt++]=i;
        if(cnt==N)break;
      }
      ans[--cnt]++;
    break;
    case 6:
      ans[0]=2;cnt=ans[1]=3;ans[2]=4;
      For(i,8,M){
        if(i%2==0||i%3==0)ans[cnt++]=i;
        if(cnt==N)break;
      }
    break;
    case 7:
      rep1(i,M){
        if(i%2==0||i%3==0)ans[cnt++]=i;
        if(cnt==N)break;
      }
    break;
  }
  output(ans);
  return 0;
}