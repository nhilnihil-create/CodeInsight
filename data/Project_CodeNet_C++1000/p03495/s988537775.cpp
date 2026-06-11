#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> cnt(200100);
  
  rep(i, n) {
    int a;
    cin >> a;
    cnt[a]++;
  }
  sort(cnt.begin(), cnt.end());
  reverse(cnt.begin(), cnt.end());
  ll ans = 0;
  rep(i, 200100) {
    if(i < k) continue;
    ans += cnt[i];
  }
  cout << ans << endl;
}