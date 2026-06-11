#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}

int main() {
  int n;
  cin >> n;
  int ans;
  rep(i,n) {
    int x;
    cin >> x;
    if(i==0) ans = x;
    ans = gcd(ans,x);
  }

  cout << ans << endl;
}