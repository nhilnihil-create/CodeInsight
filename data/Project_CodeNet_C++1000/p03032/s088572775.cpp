#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define erep(i,a,n) for(int i = a;i<=n;i++)
typedef long long ll;
#define int long long
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 110101010101010101
#define MOD 1000000007
#define P = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

signed main(){
  int n,k;
  cin >> n >> k;
  vint V(n);
  rep(i,0,n) cin >> V[i];
  int ans = 0;
  for(int l = 0;l <= k;l++){
    for(int r = 0;r <= k-l;r++){
      if(l + r > n) continue;
      int d = k - l - r;
      int now = 0;
      vint S;
      for(int i = 0;i < l;i++){
        now += V[i];
        S.push_back(V[i]);
      }
      for(int i = n-1;i >= n-r;i--){
        now += V[i];
        S.push_back(V[i]);
      }
      sort(S.begin(),S.end());
      for(int i = 0;i < d;i++){
        if(S.size() <= i) break;
        if(S[i] > 0) break;
        else now -= S[i];
      }
      ans = max(ans,now);
    }
  }
  cout << ans << endl;
}