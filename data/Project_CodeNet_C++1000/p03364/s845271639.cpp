#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int MAX = 1000000;
const int INF = 1e9;
const double pi=acos(-1);

int main(){
  int n;
  cin >>n;
  vector<string>s(n);
  rep(i,n)cin >> s[i];
  
  ll ans=0;
  rep(k,n){
    vector<string>t(n,string(n,' '));
    rep(i,n){
      rep(j,n){
        t[i][(j+k)%n]=s[i][j];
      }
    }
    bool ok=true;
    rep(i,n){
      rep(j,n){
        if(t[i][j]!=t[j][i])ok=false;
      }
    }
    if(ok)ans++;
  }
  cout << ans*n << endl;
  return 0;
}
