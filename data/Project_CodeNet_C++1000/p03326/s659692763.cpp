#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define int long long
using P = pair<int,int>;

signed main(){
  int n,k;
  cin >> n >> k;
  vint X(n),Y(n),Z(n);
  rep(i,n) cin >> X[i] >> Y[i] >> Z[i];
  int ans = 0;
  rep(i,2){
    rep(j,2){
      rep(s,2){
        vint tmp(n);
        rep(t,n){
          if(i == 0) tmp[t] -= X[t];
          else tmp[t] += X[t];
          if(j == 0) tmp[t] -= Y[t];
          else tmp[t] += Y[t];
          if(s == 0) tmp[t] -= Z[t];
          else tmp[t] += Z[t];
        }
        sort(tmp.begin(),tmp.end());
        int ttmp = 0;
        for(int m = n-1;m >= n-k;m--){
          ttmp += tmp[m];
        }
        ans = max(ans,ttmp);
      }
    }
  }
  cout << ans << endl;
}