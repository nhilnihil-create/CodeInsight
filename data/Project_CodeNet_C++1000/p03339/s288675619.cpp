#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <set>
#include <queue>
#include <stack>
#include <utility>
using namespace std;
typedef long long int ll;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define drep(i, n) for(int i = n - 1; i >= 0; i--)
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define yes cout << "yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define no cout << "no" << endl

const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const int mod = 1000000007;
#define PI 3.14159265359;

void P(int x) {cout << x << endl;}
void P(long x) {cout << x << endl;}
void P(double x) {cout << x << endl;}
void P(ll x) {cout << x << endl;}
void P(string x) {cout << x << endl;}
void P(char x) {cout << x << endl;}

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<pair<int, int> > v(n + 1);
  v[0] = make_pair(0, 0);
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == 'W') v[i] = make_pair(v[i - 1].first, v[i - 1].second + 1);
    else v[i] = make_pair(v[i - 1].first + 1, v[i - 1].second);
  }
  int ans = INF;
  for (int i = 1; i <= n; i++) {
    // cout << "E: " << v[i].first << " / W: " << v[i].second << endl;
    ans = min(ans, v[i - 1].second + (v[n].first - v[i].first));
  }
  P(ans);


  return 0;
}

