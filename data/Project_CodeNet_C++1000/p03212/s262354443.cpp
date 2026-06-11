#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
ll n;
int ans = 0;
vector<int> vec={3, 5, 7};

void dfs(ll c, int b) {
  if (c > n) {
    return;
  }
  if (0b111 == b) {
    ans++;
  }
  dfs(c*10 + 7, b | 0b100);
  dfs(c*10 + 5, b | 0b010);
  dfs(c*10 + 3, b | 0b001);
}


int main()
{

  cin >> n;
  
  dfs(0, 0);
  
  cout << ans << endl;
  
  
  return 0;
}