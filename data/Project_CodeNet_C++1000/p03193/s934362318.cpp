#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int n, h, w;
  cin >> n >> h >> w;
  int a[1010];
  int b[1010];
  rep(i,n) {
    cin >> a[i];
    cin >> b[i];
  }
  int ans = 0;
  rep(i,n) {
    bool tf = true;
    if (a[i] < h) tf = false;
    if (b[i] < w) tf = false;
    if(tf) ans++;
  }
  cout << ans << endl;
}