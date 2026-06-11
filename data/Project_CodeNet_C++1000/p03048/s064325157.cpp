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

  ll r, g, b, n;
  cin >> r >> g >> b >> n;
  ll ans = 0;
  rep(i, n+1) {
    rep(j, n+1) {
      int k = (n - r*i - g*j);
      if (k >= 0 && k % b == 0) {
        ans++;
        //printf("r: %d, g: %d, b: %d\n", i, j, int(k/b));
      }
    }
  }
  cout << ans << endl;
  return 0;
}
