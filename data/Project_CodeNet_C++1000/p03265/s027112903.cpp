#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<ll> vl;
typedef vector<string> vs;
const ll mod = 1e9+7;
const ll inf = 1e17;
const int INF = 1e9;
const double PI = acos(-1);
#define fo(i, a, b) for (int i = a; i < b; i++)
#define re(i, n) fo(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(s) s.begin(), s.end()
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
int main()
{
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int x3, y3, x4, y4;
  x3 = x2 - (y2 - y1); cout << x3 << ' ';
  y3 = y2 + (x2 - x1); cout << y3 << ' ';
  x4 = x3 - (y3 - y2); cout << x4 << ' ';
  y4 = y3 + (x3 - x2); cout << y4 << endl;

  return 0;
}
