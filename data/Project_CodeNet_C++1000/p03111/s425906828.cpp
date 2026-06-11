#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

ll ans = INF;
ll n;
ll a, b, c;
vector<ll> l;

void dfs(int x, int y, int z, int u){
  if (u == n){
    if (x == 0 || y == 0 || z == 0)
      return;
    ll A = 0, B = 0, C = 0;
    ll t = 0;
    for (int i = 0; i < n; i++){
      if ((x >> i) & 1){
        A += l[i];
        t++;
      }
      if ((y >> i) & 1){
        B += l[i];
        t++;
      }
      if ((z >> i) & 1){
        C += l[i];
        t++;
      }
    }
    ans = min(ans, (t-3)*10 + abs(A - a) + abs(B - b) + abs(C - c));
  }
  else {
    dfs(x, y, z, u + 1);
    dfs(x | (1 << u), y, z, u + 1);
    dfs(x, y | (1 << u), z, u + 1);
    dfs(x, y, z | (1 << u), u + 1);
  }
}


int main(void){
  cin >> n >> a >> b >> c;
  
  l = vector<ll>(n);
  for (int i = 0; i < n; i++){
    cin >> l[i];
  }
  
  dfs(0, 0, 0, 0);
  cout << ans << endl;

  return 0;
}
