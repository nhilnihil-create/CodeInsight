#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(long long i=0; i<(int)n; i++)
#define rep2(i,a,n) for(long long i=(a); i<(int)(n); i++)
#define all(vec) vec.begin(),vec.end()
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using psi = pair<string, int>;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};
const int mod = 1e9+7;
int gcd(int a, int b){if(a%b == 0){return(b);}else{return(gcd(b, a%b));}}
int lcm(int a, int b){return a * b / gcd(a, b);}

int N, M, K, H, W, L, R;
string S, T;
signed main(){
  cin >> N;
  vi x(N), y(N), h(N);
  rep(i,N) cin >> x[i] >> y[i] >> h[i];
  
  int h0;
  if(h[0] == 0){
    rep2(i,1,N){
      if(h[i] != 0) {h0 = i; break;}
    }
    swap(x[0],x[h0]);
    swap(y[0],y[h0]);
    swap(h[0],h[h0]);
  }
  
  vvi field(101,vi(101,0));
  rep(i,101){ // data0からのpeak を計算
    rep(j,101){
      field[i][j] = h[0]+ abs(x[0]-i)+abs(y[0]-j);
    }
  }
  bool chk = true;
  rep(i,101){ 
    rep(j,101){
      chk = true;
      rep2(k,1,N){
        int H = field[i][j] -abs(i-x[k]) - abs(j-y[k]);
        if(H<0) H = 0;
        if( H != h[k] ) {
          chk = false;
          break;
        }
      }
      if(chk){
        cout << i << " " << j << " " << field[i][j] << endl;
        return 0;
      }
    }
  }
  return 0;
}
