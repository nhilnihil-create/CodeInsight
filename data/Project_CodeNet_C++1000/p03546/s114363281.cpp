#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define rep2(i,a,n) for(int i=(a); i<(int)(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using vll = vector<ll>;
using pii = pair<int, int>;
using psi = pair<string, int>;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};
const ll mod = 1e9+7;
int gcd(int a, int b){if(a<b) swap(a,b); if (a%b == 0){return(b);}else{return(gcd(b, a%b));}}
int lcm(int a, int b){return a * b / gcd(a, b);}

long long N, M, K, H, W, L, R;

int main(){
  cin >> H >> W;
  vvi c(10,vi(10));
  rep(i,10)rep(j,10) cin >> c[i][j];
  vvi wall(H,vi(W));
  rep(i,H)rep(j,W) cin >> wall[i][j];
  
  rep(k,10){
    rep(i,10){
      rep(j,10){
        c[i][j] = min(c[i][j], c[i][k]+c[k][j]);
      }
    }
  }
  /*
  rep(i,10){
    rep(j,10){
      cout << c[i][j] << " ";
    }
    cout << endl;
  }*/
  
  ll ans = 0;
  rep(i,H){
    rep(j,W){
      if(wall[i][j]== -1) continue;
      ans += c[wall[i][j]][1];
    }
  }
    
  cout << ans << endl;
  return 0;
}