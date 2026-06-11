#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n;
  cin >> n;
  int b[200100], w[200100];
  for(int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    b[i] = b[i-1];
    w[i] = w[i-1];
    if(c=='#') b[i]++;
    else w[i]++;
  }
  int ans = 1001001001;
  for(int i = 1; i <= n; i++) {
    int cnt = b[i-1] + w[n] -w[i];
    ans = min(ans,cnt);
  }
  cout << ans << endl;
  return 0;
}