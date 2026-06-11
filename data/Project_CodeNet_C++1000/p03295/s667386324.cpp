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
  int n, m;
  cin >> n >> m;
  vector<P> v(m);
  rep(i,m) {
    cin >> v[i].second >> v[i].first;
    v[i].second--; v[i].first--;
  }
  sort(v.begin(),v.end());
  int now = -1;
  int ans = 0;
  rep(i,m) {
    if(v[i].second<=now) continue;
    now = v[i].first-1;
    ans++;
  }
  cout << ans << endl;
  return 0;
}