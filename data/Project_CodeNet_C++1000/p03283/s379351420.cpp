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
#define P = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

signed main(){
  int n,m,q;
  cin >> n >> m >> q;
  vvint city(n+1,vint(n+1));
  rep(i,0,m){
    int l,r;
    cin >> l >> r;
    city[l][r]++;
  }
  rep(i,0,n){
    rep(j,0,n){
      city[i+1][j+1] += city[i][j+1] + city[i+1][j] - city[i][j];
    }
  }
  rep(i,0,q){
    int a,b;
    cin >> a >> b;
    cout << city[b][b] - city[a-1][b] - city[b][a-1] + city[a-1][a-1] << endl;
  }
}