#include<bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
long long dp[100010];
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return 1;}return 0;}
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  bool s[15][15] = {false};
  int n, m, k, tmp;
  cin >> n >> m;
  int p[m];
  rep(i,m){
    cin >> k;
    rep(j,k){
      cin >> tmp;
      s[i][tmp-1] = true;
    }
  }
  rep(i,m)
    cin >> p[i];
  int ans = 0;
  rep(i,(1<<n)){
    bool flag = true;
    int bit[15];
    rep(j,n){
      bit[j] = (i/(1<<j)%2);
      //cout << bit[j];
    }
    //cout << endl;
    rep(j,m){
      int tmp = 0;
      rep(k,n){
        tmp += s[j][k]*bit[k];
      }
      if(tmp%2!=p[j])
        flag = false;
    }
    if(flag)
      ans++;
  }
  cout << ans << endl;
}
