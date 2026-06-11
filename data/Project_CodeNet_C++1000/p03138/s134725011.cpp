#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define erep(i,a,n) for(int i = a;i<=n;i++)
typedef long long ll;
#define int long long
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define P pair<int,int>
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

signed main(){
  int n,k;
  cin >> n >> k;
  vint A(n);
  rep(i,0,n) cin >> A[i];
  vint keta(60);
  rep(i,0,60){
    rep(j,0,n){
      if(A[j]>>i&1) keta[i]++;
    }
  }
  int ans = 0;
  rrep(i,60,-1){
    if(i != -1 && !((k>>i)&1)) continue;
    int tmp = 0;
    rrep(j,60,0){
      int mask = 1LL<<j;
      if(j > i){
        if(k&mask) tmp += mask*(n-keta[j]);
        else tmp += mask*keta[j];
      }
      else if(j == i){
        tmp += mask*keta[j];
      }
      else{
        tmp += mask*max(keta[j],n-keta[j]);
      }
    }
    ans = max(ans,tmp);
  }
  /* rep(i,0,n){
    int tmp = 0;
    tmp += A[i]^k;
    ans = max(ans,tmp);
  } */
  cout << ans << endl;
}