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
#define INF 9223372036854775807
#define MOD 1000000007
#define P pair<int,int>
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

signed main(){
  int n,k;
  cin >> n >> k;
  vint x(n);
  vint y(n);
  vint xary(n);
  vint yary(n);
  rep(i,0,n){
    cin >> x[i] >> y[i];
    xary[i] = x[i];
    yary[i] = y[i];
  }
  int ans = INF;
  sort(xary.begin(),xary.end());
  sort(yary.begin(),yary.end());
  rep(xi,0,n){
    rep(xj,xi+1,n){
      rep(yi,0,n){
        rep(yj,yi+1,n){
          int tmp = 0;
          rep(s,0,n){
            if(xary[xi] <= x[s] && x[s] <= xary[xj] && yary[yi] <= y[s] && y[s] <= yary[yj]){
              tmp++;
            }
            if(tmp >= k){
              ans = min(ans,(xary[xj] - xary[xi])*(yary[yj] - yary[yi]));
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
}