#include <bits/stdc++.h>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;
static const ll LOGN=55;


ll N, C;

int main(void) {
  cin >> N >> C;
  ll i, j, k;
  ll d[33][33]={};
  ll c[555][555]={};
  
  for(i=0; i<C; i++) {
    for(j=0; j<C; j++) {
      cin >> d[i][j];
    }
  }
  
  for(i=0; i<N; i++) {
    for(j=0; j<N; j++) {
      cin >> c[i][j];
      c[i][j]--;
    }
  }
  
  ll score[3][33]={};
  for(k=0; k<C; k++) {
    for(i=0; i<N; i++) {
      for(j=0; j<N; j++) {
        ll pclr=c[i][j];
        score[(i+j)%3][k]+=d[pclr][k];
      }
    }
  }
  
  ll ans=INF;
  for(i=0; i<C; i++) {
    for(j=0; j<C; j++) {
      for(k=0; k<C; k++) {
        if(i==j || j==k || k==i) continue;
        
        chmin(ans, score[0][i]+score[1][j]+score[2][k]);
      }
    }
  }
  
  pt(ans);
}




