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
int __stoi(string s){ return atoi(s.c_str()); }
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }

int main(){
  ll N,K; cin>>N>>K;
  ll a[N]; CINA(a,N);
  // 桁DP (上からx桁目までが (1:不一致 or 0:一致) であるときの最大値)
  ll dp[50][2];
  FILL2(dp,50,2,-1);
  dp[45][0] = 0;
  REPR(d,44){
    // d+1 桁目について
    ll mask = (1LL<<d);
    // bit1の総数
    ll c = 0;
    REP(i,N){
      if(a[i]&mask){ ++c; }
    }
    // 一致パターンからの遷移
    if(dp[d+1][0]>=0){
      if( K & mask ){ // Kの該当桁がbit1
        // bit1(Kの該当桁と同じ)を選択
        chmax(dp[d][0],dp[d+1][0] + mask*(N-c) );        
        // bit0(Kの該当桁と異なる)を選択
        chmax(dp[d][1],dp[d+1][0] + mask*c);        
      }else{ //Kの該当桁がbit0
        // bit0(Kの該当桁と同じ)を選択
        chmax(dp[d][0],dp[d+1][0] + mask*c);
      }
    }
    
    // 不一致なパターンからの遷移
    if(dp[d+1][1]>=0){
      // 自由に遷移
      chmax(dp[d][1], dp[d+1][1]+mask*(N-c) ); 
      chmax(dp[d][1], dp[d+1][1]+mask*c);
    }
  }
  ll ans = max(dp[0][0],dp[0][1]);
  cout << ans << "\n";
  
}
