#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long mod = 1000000007LL;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vi> a(h,vi(w));
  rep(i,h)rep(j,w) cin >> a[i][j];
  vector<vi> ans;
  rep(i,h) {
    if(i%2==0) rep(j,w) {
      if(j!=w-1) {
        if(a[i][j]%2==1) {
          a[i][j]--;
          a[i][j+1]++;
          ans.push_back({i+1,j+1,i+1,j+2});
        }
      }
      else if(j==w-1 && i!=h-1) {
        if(a[i][j]%2==1) {
          a[i][j]--;
          a[i+1][j]++;
          ans.push_back({i+1,j+1,i+2,j+1});
        }
      }
    }
    else per(j,w) {
      if(j!=0) {
        if(a[i][j]%2==1) {
          a[i][j]--;
          a[i][j-1]++;
          ans.push_back({i+1,j+1,i+1,j});
        }
      }
      else if(j==0 && i!=h-1) {
        if(a[i][j]%2==1) {
          a[i][j]--;
          a[i+1][j]++;
          ans.push_back({i+1,j+1,i+2,j+1});
        }
      }
    }
  }
  int n = ans.size();
  cout << n << endl;
  rep(i,n) cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << endl;
  return 0;
}