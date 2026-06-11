#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=510000;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  int k;
  cin >> k;
  vector<ll>a(k);
  rep(i,k)cin >> a[i];
  reverse(a.begin(),a.end());
  ll l=2,r=2;
  rep(i,k){
    ll mi = ((l+a[i]-1)/a[i])*a[i];
    ll ma = (r/a[i])*a[i] + a[i] -1;
    if(mi > r || ma < l){
      cout << -1 << endl;
      return 0;
    }
    l = mi;
    r = ma;
  }
  cout << l<< " " << r<< endl;
  return 0;
}
