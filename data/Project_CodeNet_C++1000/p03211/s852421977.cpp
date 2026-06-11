#include <bits/stdc++.h>
#include <set>
#include <numeric>
#define rep(i,n) for (int i=0; i < (n); ++i)
#define all(a) a.begin(), a.end()
using ll = long long;
using namespace std;
 
// ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }


// const double PI = acos(-1);
// int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }
// int a[12][12];
//平方根　= sqrt

int solve() {
  string s; cin >> s;
  
  int n = s.size();

  int ans = 999;
  for (int i=0;i <= n-3; ++i) {
    int num = (s[i]-'0')*100 + (s[i+1]-'0')*10 + (s[i+2]-'0');
    ans = min(ans,abs(num-753));
  }

  cout << ans << endl;
}


int main(){
  solve();
  return 0;
}
