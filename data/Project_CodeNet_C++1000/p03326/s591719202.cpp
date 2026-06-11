//自分用テンプレート・ライブラリ

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
#define fi first
#define se second
#define FOR(i,N) for(int i=0; i<N; i++)
#define cinv(v,N) vector<int> v(N); for(int i=0; i<N; i++){ cin >> v[i]; }
#define mt make_tuple
#define vll vector<long long int>
#define vvll vector<vector<long long int>>
#define all(v) (v).begin(),(v).end()
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

//Combination計算
const int LIMIT = 1e6;//1e6→50ms,1e7→500ms,1e8→5000ms程度。
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

//pair型のソート
bool compare_by_second(pair<ll,ll> a, pair<ll,ll> b){
  return a.second != b.second ? a.second < b.second : a.first < b.first;
}


int main()
{
  //input
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll N, M; cin >> N >> M;
  vll x(N), y(N), z(N); FOR(i,N){ cin >> x[i] >> y[i] >> z[i]; }
  vll tmpx(N), tmpy(N), tmpz(N);
  vll sum(N);
    
  //main
  ll ans = 0;
  for(int i=0; i<8; i++){
    if((i>>0)%2 == 1){//zを負にする。
      FOR(i,N){ tmpz[i] = -z[i]; }
    }else{
      FOR(i,N){ tmpz[i] = z[i]; }
    }
    if((i>>1)%2 == 1){//yを負にする。
      FOR(i,N){ tmpy[i] = -y[i]; }
    }else{
      FOR(i,N){ tmpy[i] = y[i]; }
    }
    if((i>>2)%2 == 1){//xを負にする。
      FOR(i,N){ tmpx[i] = -x[i]; }
    }else{
      FOR(i,N){ tmpx[i] = x[i]; }
    }
    FOR(i,N){ sum[i] = tmpx[i]+tmpy[i]+tmpz[i]; }
    sort(all(sum),greater<ll>());
    ll tmp = 0;
    FOR(i,M){ tmp += sum[i]; }
    ans = max(ans,tmp);
  }
  
  // output
  cout << ans << endl;

  return 0;
}
