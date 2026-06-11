#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

const int INF = 1e9;
const int cost[] = {0,2,5,5,4,5,6,3,7,6};

bool comp(pair<int,string> a, pair<int,string> b){
    return a.second > b.second;
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  rep(i,m) cin >> a[i];

  vector<int> dp(n+1,-INF);
  dp[0] = 0;
  rep(i,n+1) {
    rep(j,m) {
      if (i - cost[a[j]] >= 0) dp[i] = max(dp[i], dp[i-cost[a[j]]] + 1);
    }
  }
  vector<pair<int,string>> p(m);
  rep(i,m) {
    string s = {char(a[i] + '0')};
    p[i] = {cost[a[i]], s};
  }

  sort(p.begin(), p.end(), comp);

  int N = dp[n];
  int match = n;
  string res = "";

  while (match > 0) {
    rep(i,m) {
      if (match - p[i].first >= 0 && dp[match - p[i].first] == N-1) {
        res += p[i].second;
        N--;
        match -= p[i].first;
        break;
      }
    }
  }
  cout << res << endl;
  return 0;
} 