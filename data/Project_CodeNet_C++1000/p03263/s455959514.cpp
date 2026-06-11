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

int N, M, K, H, W, L, R, T, X;
string S;
signed main(){
  cin >> H >> W;
  vvi a(H,vi(W));
  int odd = 0;
  rep(i,H){rep(j,W){
    cin >> a[i][j];
    if(a[i][j]%2 == 1) odd++;
  }}
  if (odd <=1){
    cout << 0 << endl;
    return 0;
  }

  int cnt = 0;
  int dir = 1;
  int i = 0;
  int j = 0;
  vvi ans;
  while (1){
    int ni = i;
    int nj = j+dir;
    if(i%2 == 0 && nj == W){
      dir = -1;
      nj = W-1;
      ni = i+1;
    }
    if(i%2 == 1 && nj == -1){
      dir = 1;
      nj = 0;
      ni = i+1;
    }
   
    if(ni >= H) break;
      
    if(a[i][j]%2 == 1){
      cnt++;
      vi b = {i+1, j+1, ni+1, nj+1};
      ans.push_back(b);
      a[ni][nj]++;
      if(a[ni][nj]%2 == 0) odd--;
    } 
    i = ni;
    j = nj;
    if(odd<2) break;
  }
  
  cout << cnt << endl;
  rep(i,ans.size()){
    cout << ans[i][0]<< " " << ans[i][1] << " "<< ans[i][2]<< " " << ans[i][3] << endl;
  }
  return 0;
}