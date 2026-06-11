#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()

int main(){
  ll N;cin>>N;
  int F[N][5][2];
  int P[N][11];
  rep(i,N)rep(j,5)rep(k,2) cin>>F[i][j][k];
  rep(i,N)rep(j,11) cin>>P[i][j];
  ll ans=-1e9;
  for(int bit=1;bit<(1<<10);++bit){
    ll tmp_P = 0;    
    rep(i,N){
      ll both_open = 0;
      for(int block=0;block<10;++block){
        //i 0(月朝)~9(金夜)について、営業中の場合
        if(bit & (1<<block)) {        
          int weekday = int(block/2);
          int time = block%2;
          if(F[i][weekday][time]==1) both_open++;
        }
      }
      tmp_P += P[i][both_open];
    }
    ans = max(ans,tmp_P);
  }
  cout << ans << endl;
  }