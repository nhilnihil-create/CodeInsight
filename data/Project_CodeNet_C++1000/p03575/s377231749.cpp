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
#define shows(s) for(auto x : s){ cout << x << " "; } cout << endl;
#define showvp(v) FOR(i,v.size()){ cout << v[i].first << " " << v[i].second << endl; } cout << endl;

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

class CC{
  public:
  map<ll,int> mp;//0-indexed
  map<int,ll> rmp;
  bool isUnique = true;
  
  CC(vector<ll> v){//座標圧縮が必要になるのはlonglongintの時が多い？
    sort(v.begin(),v.end());
    auto result = unique(v.begin(),v.end());
    isUnique = (result == v.end());
    v.erase(result, v.end());//重複を除いてもmapから参照できる。
    
    for(int i=0; i<(int)v.size(); i++){
      mp.emplace_hint(mp.end(),v[i],i);//key→value
      rmp.emplace_hint(rmp.end(),i,v[i]);//value→key
    }
  }
  
  ll getKey(int value){//keyが必要な場合は座標圧縮前のベクトルから参照できるため、これは不要？
    //座標圧縮後valueに対応するkeyを取得→0-indexedの時value+1番目のkey→v[value]で良いのでは？
    //key0がvalue0に対応している点に注意。
    return this->rmp[value];
  }
  
  /*
  inline int operator [] (ll index) const{//読み取り
     if(mp.find(index) != mp.end()) return mp[index];
     else{ return -1;}
  }
  */
};

struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};

int main()
{
  //input
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int N, M; cin >> N >> M; 
  vector<int> A(M), B(M); 
  FOR(i,M){ 
    cin >> A[i] >> B[i]; 
    A[i] --; B[i] --;
  }
  
  //main
  int ans = 0;
  for(int i=0; i<M; i++){
    UnionFind uf(N);
    for(int j=0; j<M; j++){
      if(j==i) continue;
      uf.merge(A[j],B[j]);
    }
    if(!uf.issame(A[i],B[i])) ans ++;
  }
  
  // output
  cout << ans << endl;

  return 0;
}
