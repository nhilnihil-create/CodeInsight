#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define FILL(a,x); REP(i,sizeof(a)){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define FILL2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m); REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
#define LINY "YES\n"
#define LINN "NO\n"

#define umap unordered_map
//cout << setfill('0') << right << setw(4) << 12; // "0012"
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}


struct cond{
  ld l;
  ld r;
  ld v;
};

int N;
ld t[200],v[200];
umap<ld,ld> v_run;
ld T = 0;
vector<cond> conds;

ld func(cond c,ld x){
  if(x <= c.l){ return c.v+(c.l-x); }
  else if(x<= c.r){ return c.v;}
  else{ return c.v+(x-c.r); }
}


int main(){
  cin>>N;
  REP(i,N){
    int temp; cin>>temp;
    T += temp;
    if(i==0){ t[i] = temp; }
    else{ t[i] = t[i-1]+temp; }
  }
  CINA(v,N);
  conds.push_back({0,0,0});
  REP(i,N){
    if(i==0){
      conds.push_back({0,t[i],v[i]});
    }else{
      conds.push_back({t[i-1],t[i],v[i]});
    }
  }
  conds.push_back({T,T,0});
  
  for(ld a=0;a<=T; a+=0.5){
    ld temp = 200;
    for(cond c:conds){
      temp = min(temp, func(c,a));
    }
    v_run[a] = temp;
  }
  
  ld ans = 0;
  for(ld a=0;a<T; a+=0.5){
    ans += (v_run[a]+v_run[a+0.5])*0.5/2;
  }
  printf("%.4Lf\n",ans);
}