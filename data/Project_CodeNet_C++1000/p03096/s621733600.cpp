#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int inf=1<<30;

int color[200010];
ll dp[200010];

int main(){
  int n; cin >> n;
  vector<int> c(n);
  rep(i,n) cin >> c[i];
  rep(i,200010) color[i]=-1;
  dp[0]=1;
  rep(i,n-1){
    color[c[i]]=i;
    dp[i+1]+=dp[i];
    if(color[c[i+1]]!=-1&&color[c[i+1]]!=i) dp[i+1]+=dp[color[c[i+1]]];
    dp[i+1]%=mod;
  }
  cout << dp[n-1] << endl;
}