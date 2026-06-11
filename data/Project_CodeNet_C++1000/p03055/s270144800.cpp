#include "bits/stdc++.h"
#include <unordered_set>
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define vll vector<vector<long long>>
#define vl vector<long long>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pf push_front
#define ld long double
#define Sort(a) sort(a.begin(),a.end())
#define cSort(a,cmp) sort(a.begin(),a.end(),cmp)
#define reSort(a) sort(a.rbegin(), a.rend())
static const ll llMAX = numeric_limits<long long>::max();
static const int intMAX = numeric_limits<int>::max();
static const ll  llMIN = numeric_limits<long long>::min();
static const int intMIN = numeric_limits<int>::min();
static const ll d_5 = 100000;
static const ll d9_7 = 1000000007;
static const ll d_9 = 1000000000;
static const double PI=3.14159265358979323846;

template<class T>
void Printvector(std::vector<T> a){
  int size = a.size();
  rep(i,size){
    cout<<a[i]<<" ";
  }
  cout<<endl;
}
template<class T>
void Printvector(std::vector<std::vector<T>> a){
  int size = a.size();
  rep(i,size){
    int size2=a[i].size();
    rep(j,size2){
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
}
ll digitpower(ll a,ll b){//aのb乗を計算
  if(b==1){
    return a;
  }else if(b==0){
    return 1;
  }
  int mode=0;
  if(b%2==1){
    ll tmp = digitpower(a,(b-1)/2);
    if(mode==1){
      tmp%=d9_7;
    }
    tmp*=tmp;
    if(mode==1){
      tmp%=d9_7;
    }
    tmp*=a;
    if(mode==1){
      return tmp%d9_7;
    }else{
      return tmp;
    }
  }else{
    ll tmp = digitpower(a,(b)/2);
    if(mode==1){
      tmp%=d9_7;
    }
    tmp*=tmp;
    if(mode==1){
      tmp%=d9_7;
    }
    if(mode==1){
      return tmp%d9_7;
    }else{
      return tmp;
    }
  }
}

vl facs(2000010,-1);
ll Factrial(ll num){
  if(facs[num]!=-1){
    return facs[num];
  }
  if(num==1||num<=0){
    return 1;
  }else if(num<0){
    printf("ERROR_minus\n");
    return 0;
  }else{
    facs[num]=(num*Factrial(num-1))%d9_7;
    return facs[num];
  }
}
long long modinv(long long a, long long m) {//modの逆元

    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}

vl invs(2000010,-1);
ll linercomb(ll n,ll k, ll mod){//n,kの線形時間で求める
if(n<k)return 0;
if(n<0)return 0;
if(k==0 || k==n)return 1;
  ll ans=Factrial(n);
  if(invs[k]==-1){
    invs[k]=modinv(Factrial(k),mod);
  }
  ans*=invs[k];
  ans%=d9_7;
  ll k1=Factrial(n-k);
  k1%=mod;
  ans*=modinv(k1,mod);
  ans%=mod;
  return ans;
}
unordered_map<ll,ll> prime_factor(int64_t n) {
  unordered_map<ll,ll> ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

template<class T>
vector<T> getaccum(vector<T> a){
  int size=a.size();
  vector<T> ans(size);
  ans[0]=a[0];
  for(int i=0;i<size-1;i++){
    ans[i+1]=ans[i]+a[i+1];
    //ans[i+1]%=d9_7;
  }
  return ans;
}

ll getaccumnum(vector<ll> accum,int l,int r){//閉区間[l,r]の総和
  if(l==0){
    return accum[r];
  }else{
    return accum[r]-accum[l-1];
  }
}

struct datas{
  ll p;
  ll q;
};/*
bool cmp(const datas &a, const datas &b)
{
    return a.num < b.num;
}*/
template<class T>
T gcd(T a,T b){
  if(a==0){
    return b;

  }else if(b==0){
    return a;
  }
  while(1) {
    if(a < b) swap(a, b);
    if(!b) break;
    a %= b;
  }
  return a;
}
int LCS(string s,string t) {
  int n=s.size();
  int m=t.size();
  vector<vector<int>> dp=vector<vector<int>>(n+1,vector<int>(m+1,0));
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (s[i] == t[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
            }
            else {
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    return dp[n][m];
}

//グラフ
struct edge{
  int to;
  ll length;
  int num;
  int pair;
};
struct treev{
  int num;
  vector<int> nexts;
};
vector<treev> vs;
vector<edge> es;
 
int cmax=0;
void createtreenode(int num){//引数は頂点の数
  vs=vector<treev>(num);
  /*treev* newt;
  try{
      treev* newt=new treev;
  }
  catch (std::bad_alloc&) {
      // メモリ確保に失敗
      // エラー処理
  }*/
  rep(i,num){
    vs[i].num=i;
  }
  return ;
}
void insertree_bidire(ll len,int Va,int Vb,int num){//結ぶ頂点を
  //双方向
  es.pb({Va,len,num,-1});
  es.pb({Vb,len,num,-1});
  int size=es.size();
  es[size-1].pair=size-2;
  es[size-2].pair=size-1;
  vs[Va].nexts.push_back(size-1);
  vs[Vb].nexts.push_back(size-2);
  
  return;
}
void insertree_unidire(ll len,int Va,int Vb,int num){//結ぶ頂点を
  //単方向,aからbへ
  es.pb({Vb,len,num,-1});
  int size=es.size();
  es[size-1].pair=-1;
  vs[Va].nexts.push_back(size-1);
  return;
}
int dmax=0;
int now;
void DFS1(int root,ll depth,int pre){
  //ここにやりたい処理を書く
  if(depth>dmax){dmax=depth;now=root;}
  for(auto i:vs[root].nexts){
    if(pre==es[i].to){
      continue;
    }
    
    DFS1(es[i].to,depth+es[i].length,root);
  }
  return;
}
int now2;
void DFS2(int root,ll depth,int pre){
  //ここにやりたい処理を書く
  if(depth>dmax){dmax=depth;now2=root;}
  for(auto i:vs[root].nexts){
    if(pre==es[i].to){
      continue;
    }
    
    DFS2(es[i].to,depth+es[i].length,root);
  }
  return;
}
int main(void){
  int n;
  cin>>n;
  createtreenode(n);
  rep(i,n-1){
    int u,v;
    cin>>u>>v;
    u--;v--;
    insertree_bidire(1,u,v,i);
  }
  DFS1(0,1,-1);
  int v1=now;
  dmax=0;
  DFS2(v1,1,-1);
  int d=dmax+2;
  int v2=now2;
  if(d%3==1){
    cout<<"Second"<<endl;
  }else{
    cout<<"First"<<endl;
  }
  return 0;
}

//<<std::setprecision(30)

//重複削除
 /* std::sort(vec.begin(), vec.end());
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());*/
