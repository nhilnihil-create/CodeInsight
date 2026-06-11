#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)

int main()
{
  int n,m;
  cin >> n >> m;
  
  int x[m];
  rep(i,m) cin >> x[i];
  
  sort(x,x+m);
  
  int dis[m-1];
  rep(i,m-1) dis[i] = x[i+1] - x[i];
  
  sort(dis,dis+(m-1));
  
  ll ans = 0;
  for(int i = 0; i < m-1-(n-1); i++)
  {
    ans += dis[i];
  }
  
  cout << ans << endl;
}
