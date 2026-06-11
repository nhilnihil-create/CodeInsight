#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
using namespace std;
using namespace __gnu_pbds;
using ll = int64_t;
using ld = long double;
using ull = uint64_t;
using pl = pair<ll, ll>;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ll n;

vector<ll> p, a;

int main() {
  ios::sync_with_stdio(0);
  cout.precision(10);

  cin >> n;
  p.resize(n);
  a.resize(n+1);
 
 for (int i = 0; i < n; i++) {
   cin >> p[i];
 }
 
 for (int i = 0; i < n; i++) {
  ll v = p[i];
  a[v] = max(a[v], a[v-1]+1);
 }
 ll mmax = 0;
 for (int i = 1; i <= n; i++) {
  mmax = max(a[i], mmax); 
 }
 cout << n - mmax << endl;
}