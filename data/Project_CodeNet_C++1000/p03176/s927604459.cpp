#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
#define inputInt(a) int a; cin >> a; 
#define inputInt2(a,b) int a; int b; cin >> a >> b; 
#define inputInt3(a,b,c) int a; int b; int c; cin >> a >> b >> c;
#define inputLong(a) long a;cin >> a; 
#define inputIntArray(a,N) int a[N];for(int i=0;i<N;i++){cin >> a[i];}
#define inputLongArray(a,N) long a[N];for(int i=0;i<N;i++){cin >> a[i];}
#define inputIntArray2(a,b,N) int a[N]; int b[N]; for(int i=0;i<N;i++){cin >> a[i] >> b[i];}
#define output(answer) cout << answer << endl;
#define fN(i,N)    for(int i=0; i<N; i++)
#define fSE(i,s,e) for(int i=s; i<=e; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define FOR(i,N) for(int i=0; i<N; i++)
#define cinv(v,N) vector<int> v(N); for(int i=0; i<N; i++){ cin >> v[i]; }
#define mt make_tuple
#define vll vector<long long int>
#define vvll vector<vector<long long int>>
#define vvvll vector<vector<vector<long long int>>>
#define all(v) (v).begin(),(v).end()
#define lb lower_bound
#define ub upper_bound
#define message cout<<"now debugging…"<<endl
#define show(v) FOR(i,v.size()){ cout << v[i] << " "; } cout << endl;
#define showshow(v) FOR(i,v.size()){ FOR(j,v[i].size()){ cout << v[i][j] << " "; } cout << endl; }
#define showshowshow(v) FOR(i,v.size()){ FOR(j,v[i].size()){ FOR(k,v[i][j].size()){ cout << v[i][j][k] << "|"; } cout << " "; } cout << endl; }
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e18;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

//Combination計算 //ComInitしないと何もできません。
const int LIMIT = 1e6+1;//1e6→50ms,1e7→500ms,1e8→5000ms程度。
//const ll MOD = 1e9+7;
vector<ll> FacMod(LIMIT), InvMod(LIMIT), FacInvMod(LIMIT);
const int dpComTableLIMIT = 3e3+1;
vector<vector<ll>> Com(dpComTableLIMIT,vector<ll>(dpComTableLIMIT,0));
const int ComKTableLIMIT = 1e7;
vector<ll> ComK(ComKTableLIMIT);

void DPComInit(){
  //Com[0][j]は0で初期化されている。
  for(int i=0; i<dpComTableLIMIT; i++){ Com[i][0] = 1; }
  
  for(int i=1; i<dpComTableLIMIT; i++){
    for(int j=1; j<dpComTableLIMIT; j++){
      Com[i][j] = (Com[i-1][j-1]+Com[i-1][j])%MOD;
    }
  }
}

void ComKInit(ll N){
  for(int i=0; i<=ComKTableLIMIT; i++){
    if(0<i && i<=N/2){
      ComK[i] = (ComK[i-1]*(N-i+1)/i)%MOD;
    }else if(i==0){
      ComK[i] = 1;
    }else if(N/2<i && i<=N){
      ComK[i] = ComK[N-i];
    }else{//i>Nの時
      ComK[i] = -1;
    }
  }
}

void ComInit(){//tableを作成
  FacMod[0] = FacMod[1] = 1;
  InvMod[0] = 0; InvMod[1] = 1; //InvMod[0]は定義できない
  FacInvMod[0] = FacInvMod[1] = 1;
  
  for(int i=2; i<LIMIT; i++){
    FacMod[i] = FacMod[i-1]*i%MOD;
    InvMod[i] = -InvMod[MOD%i]*(MOD/i)%MOD + MOD;
    FacInvMod[i] = FacInvMod[i-1] * InvMod[i]%MOD;
  }
}

ll ComMod(int n, int k){
  if(n>=0 && k>=0 && n>=k){
    return FacMod[n]*(FacInvMod[k]*FacInvMod[n-k]%MOD)%MOD;
  }else{
    return 0; //戻り値を0にする方が計算結果に影響が少ない。
  }
}


//繰り返し2乗法
ll power(ll x, ll y){//繰り返し2乗法
  if(y < 0){
    return 0;
  }else if(y == 0){
    return 1LL;
  }else if(y%2 == 0){//偶数
    return power(x,y/2)*power(x,y/2);
  }else{//奇数
    return power(x,y-1)*x;
  }
}

//繰り返し2乗法
ll mpower(ll x, ll y, ll m){//繰り返し2乗法
  if(y < 0){
    return 0;
  }else if(y == 0){
    return 1LL;
  }else if(y%2 == 0){//偶数
    return mpower(x,y/2,m)*mpower(x,y/2,m)%m;
  }else{//奇数
    return mpower(x,y-1,m)*x%m;
  }
}

//互除法
ll GCD(ll a, ll b){
  return b ? GCD(b,a%b) : a;
}

ll LCM(ll a, ll b){
  return (a / GCD(a,b))*b;
}

//素因数分解
pair<map<ll,ll>,bool> PrimeFactorization(ll N){
  pair<map<ll,ll>,bool> ret;//<素因数分解,素数判定>
  ret.second = true;
  
  //素因数分解
  if(N != 2){
    while(N%2 == 0){//p=2の時。
      N /= 2;
      ret.first[2] ++;
      ret.second = false;
    }
  }
  for(ll i=3; i*i<=N; i+=2){//p>=3の時。
    while(N%i == 0){
      N /= i; 
      ret.first[i] ++;
      ret.second = false;
    }
  }
  if(N != 1){//Nが素数の時
    ret.first[N] ++;
  }
  
  //返り値
  return ret;
}

//pair型のソート
bool compare_by_second(pair<ll,ll> a, pair<ll,ll> b){
  return a.second != b.second ? a.second < b.second : a.first < b.first;
}

template< typename Monoid >
struct SegmentTree {
  using F = function< Monoid(Monoid, Monoid) >;

  int sz;
  vector< Monoid > seg;

  const F f;
  const Monoid M1;

  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }

  void set(int k, const Monoid &x) {
    seg[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  Monoid query(int a, int b) {
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, seg[a++]);
      if(b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }

  Monoid operator[](const int &k) const {
    return seg[k + sz];
  }

  template< typename C >
  int find_subtree(int a, const C &check, Monoid &M, bool type) {
    while(a < sz) {
      Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
      if(check(nxt)) a = 2 * a + type;
      else M = nxt, a = 2 * a + 1 - type;
    }
    return a - sz;
  }


  template< typename C >
  int find_first(int a, const C &check) {
    Monoid L = M1;
    if(a <= 0) {
      if(check(f(L, seg[1]))) return find_subtree(1, check, L, false);
      return -1;
    }
    int b = sz;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) {
        Monoid nxt = f(L, seg[a]);
        if(check(nxt)) return find_subtree(a, check, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }

  template< typename C >
  int find_last(int b, const C &check) {
    Monoid R = M1;
    if(b >= sz) {
      if(check(f(seg[1], R))) return find_subtree(1, check, R, true);
      return -1;
    }
    int a = sz;
    for(b += sz; a < b; a >>= 1, b >>= 1) {
      if(b & 1) {
        Monoid nxt = f(seg[--b], R);
        if(check(nxt)) return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};

bool isOK(ll condition){
  //return false;
  return true;
}

ll binary_search(){
  //最小値を求める時
  ll ok = 1e18;//解が存在する最大値
  ll ng = -1;//解が存在しない最小値
  /*
  //最大値を求める時
  ll ok = -1;//解が存在する最小値
  ll ng = 1e18;//解が存在しない最大値
  */
  
  while(abs(ok-ng) > 1){
    ll mid = (ok+ng)/2;
    if(isOK(mid)){
      ok = mid; 
    }else{
      ng = mid;
    }
  }
  return ok;
}



int main()
{
  //input
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll N; cin >> N;
  vector<ll> H(N), A(N);
  FOR(i,N){ cin >> H[i]; H[i] --; }
  FOR(i,N){ cin >> A[i]; }
  SegmentTree<ll> seg(N,[](ll a, ll b){return max(a,b);},0);
  seg.update(H[0],A[0]);
  
  //main
  for(int i=1; i<N; i++){
    ll M = seg.query(0,H[i]);
    seg.update(H[i],M+A[i]);
  }
  
  // output
  ll ans = seg.query(0,N);
  cout << ans << endl;

  return 0;
}