#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<vector<ll>> Matrix;

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
ll lcm(ll a, ll b) { return a*b/gcd(a, b);}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll a, b, c;
  cin >> a >> b >> c;
  vector<ll> v;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  sort(v.begin(), v.end(), greater<ll>());
  cout << v[0]*10+v[1]+v[2] << endl;
  return 0;
}
