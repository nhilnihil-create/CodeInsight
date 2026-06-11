#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) int((a).size())
#define SORT(c) sort((c).begin(),(c).end())
#define PB push_back
#define MP make_pair
#define MEMSET(v, h) memset((v), h, sizeof(v))
#define sqr(x)  ((x) * (x)) 
#define cub(x)  ((x) * (x) * (x))
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
// ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
  int n; cin >> n;
  int d[n];
  int circle[25];
  MEMSET(circle,0);
  int ref = 0;
  ++circle[0];
  FOR(i,0,n-1) cin >> d[i];
  sort(d,d+n);
  FOR(i,0,n-1) {
    if(d[i]==0 || d[i]==12){
      ++circle[d[i]];
    } else if(ref%2==0) {
      ++circle[d[i]];
      ++ref;
    } else {
      ++circle[(24-d[i])%24];
      ++ref;
    }
  }

  int ans = 24;

  FOR(i,0,23){
    FOR(j,0,23){
      if(circle[i]!=1 || circle[j]!=1) continue;
      if(i==j) continue;

      chmin(ans,abs(i-j));

      // cout << i << " " << j << " " << ans << endl;
    }
  }

  FOR(i,0,23){
    if(circle[i]>1) ans = 0;
  }

  cout << ans << endl;
  


}
