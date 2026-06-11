#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n, ans;
  double t, a, q;
  cin >> n >> t >> a;
  double x[n];
  rep(i, n) cin >> x[i];
  double mini = 1000000;
  rep(i, n){
    q = t - x[i] * 0.006;
    mini = min(mini, abs(a - q));
  }
  rep(i, n){
    q = t - x[i] * 0.006;
    if(abs(q - a) == mini) ans = i + 1;
  }
    
  cout << ans << endl;
  return 0;
}