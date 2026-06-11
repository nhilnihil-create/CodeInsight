#include <bits/stdc++.h>
#include <set>
#define rep(i,n) for (int i=0; i < (n); ++i)
#define all(a) a.begin(), a.end()
using ll = long long;
using namespace std;
 
// ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }


// const double PI = acos(-1);


int main() {
  int n,k; cin >> n >> k;
  int x = n+1;
  if (x/2 >= k) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
