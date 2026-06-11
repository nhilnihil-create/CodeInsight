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

#define rep(i,n) ;for( int i =0; i < n ; i ++)
#define all(a) a.begin(),a.end()
#define pb(a) push_back(a)
#define pd(a) printf("%.10f\n",a)
#define mem(a) memset(a,0,sizeof(a))
#define f(i,a,b) for(int i=a;i<b;i++)
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
  for(ll i=0;i<=n;i++){
    num*=yakusu[i];
  }
  return num;
}

int H,W;
vs s(50);
vi dv ={-1,0,1,0};vi du={0,-1,0,1};
int cnt=1;
int dfs(int u,int v){
  s[u][v]='.';
  
  rep(i,4){
   
      int nu =u +du[i],nv=v+dv[i];
      if(nu<0||nu>=H||nv<0||nv>=W)continue;
      if(s[nu][nv]=='.')continue;
      cnt ++;
      dfs(nu,nv);
    
  }
  return cnt;

}

//vc alp(26) ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
//cout<<""<<endl;
int main(){
  ll N;cin>>N;vl A(N);rep(i,N)cin>>A[i];
  vl sa(N+10);sa[0]=abs(A[0]);sa[N]=abs(A[N-1]);
  ll tot= sa[0]+sa[N];
  for(int i=1;i<N;i++){
    sa[i]=abs(A[i]-A[i-1]);
    tot +=sa[i];
  }
  cout<<tot-sa[0]-sa[1]+abs(A[1])<<endl;
  for(int i=1;i<N-1;i++){
    cout<<tot-sa[i]-sa[i+1]+abs(A[i-1]-A[i+1])<<endl;
  }
  cout<<tot-sa[N-1]-sa[N]+abs(A[N-2])<<endl;
}



