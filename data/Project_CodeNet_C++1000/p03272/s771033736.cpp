#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef set<ll> sl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define rep2(i, n) for(ll i = 1; i <= ll(n); i++)
//#define rep(i, k, n) for(ll i = k-1; i < ll(n); i++)
//#define rep2(i, k, n) for(ll i = k; i <= ll(n); i++)
#define all(v) v.begin(), v.end()
//bool chmin(ll & a, ll  b) { if (b < a) { a = b; return 1; } return 0; }
//bool chmax(ll & a, ll b) { if (b > a) { a = b; return 1; } return 0; }
const ll INF = 999999999999999;
const ll MOD = 1000000007;
const ll MAX_N=500010;
ll N, i, ans=0;
int main() {
  cin >> N >> i;
  cout << N-i+1 << endl;
  return 0;
}