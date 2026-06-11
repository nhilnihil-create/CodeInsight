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
#include <stdio.h>
#include <unistd.h>
using namespace std;
typedef long long int ll;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define drep(i, n) for(int i = n - 1; i >= 0; i--)
#define itrep(itr, base) for (auto itr = base.begin(); itr != base.end(); itr++)
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define yes cout << "yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define no cout << "no" << endl
#define PI 3.14159265359

const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const int mod = 1000000007;

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
  cin >> n;
  int f[n][10];
  rep (i, n) rep (j, 10) cin >> f[i][j];
  int p[n][11];
  rep (i, n) rep (j, 11) cin >> p[i][j];

  int loop = pow(2, 10);
  ll ans = INF * -1;
  for (int i = 1; i < loop; i++) {
    ll tmpAns = 0;
    rep (mise, n) {
      int count = 0;
      rep (open, 10) {
        if (i & (1 << open) && f[mise][open] == 1) count++;
      }
      tmpAns += p[mise][count];
    }
    ans = max(ans, tmpAns);
  }
  P(ans);
  return 0;
}

