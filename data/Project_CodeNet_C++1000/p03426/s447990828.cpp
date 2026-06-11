#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;


int main(){
  int h, w, d;
  unordered_map<int, P> mp;
  int q;
  int dp[90001];
  int ans = 0;
  cin >> h >> w >> d;
  rep(i, h){
    rep(j, w){
      int a;
      cin >> a;
      mp[a] = P(i, j);
    }
  }
  
  for(int i = d+1; i <= h*w; i++){
    dp[i] = dp[i-d] + abs(mp[i].first-mp[i-d].first) + abs(mp[i].second-mp[i-d].second);
  }
  cin >> q;
  while(q--){
    int l, r;
    cin >> l >> r;
    cout << dp[r] - dp[l] <<endl;
  }
}
        
        

