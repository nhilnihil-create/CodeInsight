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
  string s;
  cin >> s;

  bool ac = true;
  if(s[0] != 'A') {
    ac = false;
  } else {
    int c = 0;
    fo(i, 2, s.size()-1) {
      if(s[i] == 'C') {
        s.erase(i, 1);
        c++;
      }
    }
    if(c != 1) ac = false;
    int a = 0;
    fo(i, 1, s.size()) {
      if(isupper(s[i])) a++;
    }
    if(a != 0) ac = false;
  }
  if(ac) cout << "AC" << endl;
  else cout << "WA" << endl;

  return 0;
}
