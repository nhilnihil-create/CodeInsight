#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

int f(int x){
  string s = "255456376";
  x--;
  return s[x]-'0';
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for(int i=0; i<m; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<int> dp(n+1, -100000000);
  dp[0] = 0;
  for(int i=1; i<=n; i++){
    for(int j=0; j<m; j++){
      if(i-f(a[j])>=0) dp[i] = max(dp[i-f(a[j])]+1, dp[i]);
    }
  }
  string ans;
  int remain = dp[n];
  int match = n;
  while(match>0){
    for(int i=m-1; i>=0; i--){
      if(match-f(a[i])<0) continue;
      if(dp[match-f(a[i])]==remain-1){
        remain -= 1;
        match -= f(a[i]);
        ans.append(to_string(a[i]));
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
