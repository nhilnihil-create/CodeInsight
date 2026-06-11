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
  int n;
  cin >> n;
  vs w(n);
  re(i, n) cin >> w[i];

  bool srtr = true;
  re(i, n-1) {
    if(w[i].back() != w[i+1].front()) srtr = false;
  }
  re(i, n-1) {
    fo(j, i+1, n) {
      if(w[i] == w[j]) srtr = false; //配列内に重複があったらfalse
    }
  }
  if(srtr) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
