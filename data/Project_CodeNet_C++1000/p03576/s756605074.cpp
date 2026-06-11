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


struct point{
  ll x;
  ll y;
};

int main(){
  int N,K; cin>>N>>K;
  point p[N];
  ll cand_x[N];
  ll cand_y[N];
  REP(i,N){
    cin>>cand_x[i]>>cand_y[i];
    p[i] = {cand_x[i],cand_y[i]};
  }
  sort(cand_x,cand_x+N);
  sort(cand_y,cand_y+N);
  
  ll ans = (cand_x[N-1]-cand_x[0])*(cand_y[N-1]-cand_y[0]);
  for(int xj=1; xj<N; ++xj){
    for(int xi=0; xi<xj; ++xi){
      for(int yj=1; yj<N; ++yj){
        for(int yi=0; yi<yj; ++yi){
          ll hidari = cand_x[xi];
          ll migi = cand_x[xj];
          ll sita = cand_y[yi];
          ll ue = cand_y[yj];
          
          int count = 0;
          REP(i,N){
            if( p[i].x>=hidari && p[i].x<=migi && p[i].y>=sita && p[i].y<=ue ){ ++count; }
          }
          if(count>=K){ ans = min(ans, (migi-hidari)*(ue-sita) ); }
        }
      }
    }
  }
  cout << ans <<"\n";
}