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
// int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main() {
  ll n; cin >> n;
  ll a[n];
  FOR(i,0,n-1) cin >> a[i];

  bool ok = true;

  ll sum = 0;

  FOR(i,0,n-1){
    if(a[i]>=a[i-1]+2) ok = false;
    else if(a[i]>i) ok = false;
    else if(a[i]-a[i-1]==1) ++sum;
    else sum += a[i];
  }

  if(!ok) cout << -1 << endl;
  else cout << sum << endl;
}

