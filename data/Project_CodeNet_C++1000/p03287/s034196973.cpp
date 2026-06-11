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
  int n,m;
  cin >> n >> m;
  vint A(n);
  rep(i,0,n){
    cin >> A[i];
  }
  vint sum(n+1);
  rep(i,0,n){
    sum[i+1] = (sum[i] + A[i])%m;
  }
  map<int,int> map;
  int ans = 0;
  rep(i,0,n+1){
    ans += map[sum[i]];
    map[sum[i]]++;
  }
  cout << ans << endl;
}