#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)
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
  ll n,k; cin >> n >> k;
  ll a[n];
  FOR(i,0,n-1) cin >> a[i];
  vector<ll> cand;

  FOR(i,0,n-1){
    ll sum = 0;
    FOR(j,i,n-1){
      sum += a[j];
      cand.PB(sum);
    }
  }

  ll mask = 0;
  FORD(i,40,0){
    int cnt = 0;
    for(ll x: cand){
      if((x & ((1LL<<i) | mask)) == ((1LL<<i) | mask)) ++cnt;
    }
    if(cnt>=k) mask |= (1LL << i);
  }

  cout << mask << endl;
}
