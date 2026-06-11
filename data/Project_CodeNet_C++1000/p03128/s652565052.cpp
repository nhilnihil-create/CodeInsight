#include<bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define rep1c(i, n) for (int i = 1; i <= (int)(n); i++)

using namespace std;

static const int MAX = 10009, NINF = -1000000009;
int N, M, A[10], dp[MAX];
map<int, int> mp;
vector<int> use;

void solve() {
  dp[0] = 0;
  rep1c(i, N) {
    dp[i] = NINF;
    for(const int& j : use) {
      if(i-mp[j]>=0 && dp[i-mp[j]]>=0) dp[i] = max(dp[i], dp[i-mp[j]] + 1);
    }
  }
  int n = N;
  vector<int> res;
  while(n>0) {
    for(const int& j : use) {
      if(n-mp[j]>=0 && dp[n] == dp[n-mp[j]] + 1) {
        res.push_back(j);
        n -= mp[j];
        break;
      }
    }
  }
  for(const int& i : res) cout << i;
  cout << endl;
}

int main() {
  mp[1] = 2;
  mp[2] = 5;
  mp[3] = 5;
  mp[4] = 4;
  mp[5] = 5;
  mp[6] = 6;
  mp[7] = 3;
  mp[8] = 7;
  mp[9] = 6;
  scanf("%d %d", &N, &M);
  rep(i, M) {
    int A;
    scanf("%d", &A);
    use.push_back(A);
  }
  sort(use.begin(), use.end());
  reverse(use.begin(), use.end());
  solve();
  return 0;
}
