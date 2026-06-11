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
  vector<int> c(n - 1);
  vector<int> s(n - 1);
  vector<int> f(n - 1);
  rep (i, n - 1) {
    cin >> c[i] >> s[i] >> f[i];
  }

  rep (i, n - 1) {
    int now = 0;
    for (int j = i; j < n - 1; j++) {
      if (now < s[j]) now = s[j];
      if (now % f[j] != 0) {
        now = (1 + (now / f[j])) * f[j];
      }
      now += c[j];
    }
    P(now);
  }
  P(0);


  return 0;
}
