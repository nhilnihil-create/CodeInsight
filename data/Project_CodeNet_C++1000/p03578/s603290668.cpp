// URL: https://atcoder.jp/contests/code-festival-2017-qualb/tasks/code_festival_2017_qualb_b

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const char wall = '#';
vector<vector<char>> fields;
vector<vector<bool>> used;
vector<vector<ll>> dist;
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0};

vector<ll> A;
// vectorのリサイズ
// A.resize(N);

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return b/gcd(a,b)*b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n;
  map<ll, int> mp;
  rep(i, n) {
    ll d;
    cin >> d;
    mp[d]++;
  }
  cin >> m;
  vector<ll> t(n);
  rep(i, m) {
    ll t;
    cin >> t;
    mp[t]--;
  }
  for(auto m: mp) {
    if (m.second < 0) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
