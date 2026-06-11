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
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;


int main(){
  int n;
  cin >> n;
  vector<ll>a(100000);
  int cnt = 0;
  rep(i, 0, n){
      ll b;
      cin >> b;
      if(b>100000){
        cnt++;
        continue;
      }
      b--;
      a[b]++;
  }
  rep(i, 0, 100000){
      if(a[i]==0)continue;
      if(a[i]>i+1)cnt += a[i]-(i+1);
      if(a[i]<i+1) cnt += a[i];
  }
  cout << cnt << endl;
}