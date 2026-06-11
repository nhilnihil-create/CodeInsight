#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n; cin >> n;

  set<int> num;
  num.insert(1);
  int x = 6;
  while(x <= n){ num.insert(x); x *= 6; }
  x = 9;
  while(x <= n){ num.insert(x); x *= 9; }

  vi dp(n+1,INF); //iを作るために必要な最小回数
  dp[0] = 0;
  for(int i = 0; i <= n; i++){
    for(auto x : num) if(i+x <= n) chmin(dp[i+x],dp[i]+1);
  }
  cout << dp[n];
  cout << "\n";
  return 0;
}
