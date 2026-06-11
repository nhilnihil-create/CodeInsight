#include <bits/stdc++.h>
#include <math.h>
#include <cmath>

using namespace std;
using ll =long long;
using vi = vector<int>; 
using vvi = vector<vi>; 
using vl = vector<ll>; 
using vvl = vector<vl>; 
using vs = vector<string>;
using vvs = vector<vs>; 
using vc = vector<char>;
using vvc = vector<vc>; 
using vb = vector<bool>;
using vvb = vector<vb>; 

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const long long INF = 1LL << 60;
typedef pair<int, int> PR;

#define rep(i,n) ;for( int i =0; i < n ; i ++)
#define all(a) a.begin(),a.end()
#define pb(a) push_back(a)
#define pd(a) printf("%.10f\n",a)
#define mem(a) memset(a,0,sizeof(a))
#define fr(i,a,b) for(int i=a;i<b;i++)
#define pri(a)  printf("%.14lf\n",a);
#define MOD 1000000007
bool is_int_lround(double x){
  return std::lround(x)==x;
}
ll keta(ll x){
  ll n=0;
  while(x>0){
    x /=10 ;
    n ++;
  }
  return n;
}

ll conbi(int n,int m){
  
  cin>>n>>m;
  vector<ll> a(100);
  a[0] =1;
  for(int i=0;i<14;i++){
    a[i+1]=a[i]*(i+1);
  }
  return a[n] /(a[m] *a[n-m]);
}

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;//繰り返し二乗法
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
ll kaijo(ll x){
  ll z=1;
  if(x==0){
    return 1;
  }
  while(x>0){
    z *=x;
    z %=MOD;
    x--;
  }
  return z;
}
ll yakusu_num(ll n){
  vl yakusu(n+1,1);
  for(ll i=2;i*i<=n;i++){ 
    while(n%i==0){
      n /=i;
      yakusu[i]++;
    }
  }
  if(n!=1)yakusu[n]++;
  ll num=1;
  for(ll i=0;i <=n;i++){
    num*=yakusu[i];
  }
  return num;
}
//cout<<""<<endl;
int N,A,B,C;;
int ans=100000000;
vi l;

void dfs(int d,vi vec){
  if(d==N){
    int a=0,b=0,c=0,cost=0;
    rep(p,N){
      if(vec[p]==1){
        if(a!=0)cost+=10;
        a+=l[p];
      }
      else if(vec[p]==2){
        if(b!=0)cost+=10;
        b+=l[p];
      }
      else if(vec[p]==3){
        if(c!=0)cost+=10;
        c+=l[p];
      }
    }
    if(a!=0&&b!=0&&c!=0)cost+=abs(A-a)+abs(B-b)+abs(C-c);
    else return;
    ans=min(ans,cost);
    return;
  }
  rep(num,4){
    vec.pb(num);
    dfs(d+1,vec);
    vec.pop_back();
  }
}
int main(){
  cin>>N>>A>>B>>C;
  vi z(N);
  rep(i,N){
    cin>>z[i];
  }
  l=z;
  dfs(1,{0});
  dfs(1,{1});
  dfs(1,{2});
  dfs(1,{3});
  cout<<ans<<endl;
}


