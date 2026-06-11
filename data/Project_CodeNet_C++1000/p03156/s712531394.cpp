#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const int INF = 1001001001;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> cnt(3);
  rep(i, n) {
    int t;
    cin >> t;
    if(t <= a) cnt[0]++;
    else if(t <= b) cnt[1]++;
    else cnt[2]++; 
  }
  int ans = INF;
  rep(i, 3) ans = min(cnt[i], ans);
  cout << ans << endl;
  
}