#include <bits/stdc++.h>
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define int long long
#define double long double
#define PI 3.141592653589793
typedef long long ll;
const int MOD = 1000000007;
const int INF = LLONG_MAX;
const double EPS = 1e-10;
using namespace std;
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 

vector<int> divisor(int n){
  vector<int> ret;
  for(int i = 1;i*i <= n;i++){
    if(n%i == 0){
      ret.push_back(i);
      if(i*i != n)ret.push_back(n/i);
    }
  }
  sort(ret.begin(), ret.end());
  return ret;
}
int n;string ss[310];char c[6100][6100];
signed main() {
  cin>>n;rep(i,n)cin>>ss[i];
  rep(i,n)rep(j,n)c[i][j] = c[i+n][j] = c[i][j+n] = c[i+n][j+n] = ss[j][i];
  int ans = 0;
  rep(i,n){
    bool b = true;
    rep(j,n){
      rep(k,n){
        b = b && (c[i+j][k] == c[i+k][j]);
      }
    }
    if(b)ans += n-i;
  }
  repd(i,1,n){
    bool b = true;
    rep(j,n){
      rep(k,n){
        b = b && (c[j][k+i] == c[k][j+i]);
      }
    }
    if(b)ans += n-i;
  }
  cout << ans << endl;
}

