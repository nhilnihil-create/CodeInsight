#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mod 1000000007
using ll = long long;
using namespace std;
int main(){
  int n,k;
  cin >> n >> k;
  ll ans = 0;
  for(int b = k + 1; b <= n; b++){
    ans += (n / b) * max(0, b - k)+ max(0, n + 1 - (n / b) * b - k);
    if(!k) ans--;
  }
  cout << ans << endl;
}