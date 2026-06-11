#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const ll inf = 1e18;
const int mod = 1e9+7;
void add_self(int &a, int b) {a+=b; if(a>=mod) a-=mod;}
void sub_self(int &a, int b) {a-=b; if(a<0) a+=mod;}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++)
    cin >> a[i];
  // dp[i][j] : min total cost of combining interval [i,j]
  vector<vector<ll>> dp(n, vector<ll>(n, inf));
  auto sum = [&](int L, int R) {
    ll s = 0;
    for(int i=L; i<=R; i++) s+=a[i];
    return s;
  };

  for(int L=n-1; L>=0; L--) {
    for(int R=L; R<n; R++) {
      if(L==R) {
        dp[L][R] = 0;
      } else {
        ll s = sum(L, R);
        for(int i=L; i<R; i++) {
          dp[L][R] = min(dp[L][R], dp[L][i]+dp[i+1][R]+s);
        }
      }
    }
  }
  cout << dp[0][n-1] << '\n';
  
  return 0;
}
