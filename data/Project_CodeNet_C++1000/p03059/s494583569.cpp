#include <bits/stdc++.h>
#define rep2(i,x,y) for (int i = x; i < (y); ++i)
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
ll INF = 1000000000;

int main()
{
  ios::sync_with_stdio(false);  cin.tie(0); cout.tie(0);
  int a,b,t;
  cin >> a >> b >> t;
  int ans = 0;
  for(int i = 1; i <= t; i++){
    if(i % a == 0) ans += b;
  }
  cout << ans << endl;
}