#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

const int MAX = 1000000;
const int MOD = 1000000007;


int main(){
   int n, m;
   cin >> n >> m;
   vector<int>imos(n+1);
   rep(i, 0, m){
       int p, q;
       cin >> p >> q;
       p--;
       imos[p]++;
       imos[q]--;
   }
   rep(i, 1, n+1){
       imos[i]+=imos[i-1];
   }
   int ans = 0;
   rep(i, 0, n+1)if(imos[i]==m)ans++;
   cout << ans << endl;
}