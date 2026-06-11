#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int n;
int ans = 0;

bool check(ll cn) {
  map<int, int> mp;
  while(cn) {
    mp[cn%10]++;
    cn/=10;
  }
  if (mp[3] == 0 || mp[7] == 0 || mp[5] == 0) {
    return false;
  } else {
    return true;
  }
}

void dfs(ll cn) {
  if (cn > n) {
    return;
  }
  if (check(cn)) ans++;
  
  dfs(cn*10 + 3);
  dfs(cn*10 + 5);
  dfs(cn*10 + 7);
}

int main()
{
  cin >> n;
  dfs(0);
  cout << ans << endl;
  return 0;
}