#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<double> vd;
typedef vector<ll> vl;
typedef vector<string> vs;
#define fo(i, a, b) for (int i = a; i < b; i++)
#define re(i, n) fo(i, 0, n)
#define pb push_back
#define all(s) s.begin(), s.end()
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
int main()
{
  int n;
  cin >> n;
  vi p(n);
  re(i, n) cin >> p[i];

  sort(all(p), greater<int>());
  p[0] /= 2;
  int s = 0;
  re(i, n) s += p[i];

  cout << s << endl;

  return 0;
}
