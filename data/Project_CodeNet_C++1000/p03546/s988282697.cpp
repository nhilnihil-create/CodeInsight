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
  int h, w;
  cin >> h >> w;
  int c[10][10];
  rep(i, 10) rep (j, 10) cin >> c[i][j];

  map<int, int> mp;
  rep (i, 10) mp[i] = 0;
  rep (i, h) {
    rep (j, w) {
      int a;
      cin >> a;
      if (a != -1 && a != 1) {
        mp[a]++;
      }
    }
  }

  rep (m, 10) {
    rep (i, 10) {
      rep (j, 10) {
        if (i == j) continue;
        c[i][j] = min(c[i][j], c[i][m] + c[m][j]);
      }
    }
  }

  ll ans = 0;
  rep (i, 10) {
    if (i == 1) continue;
    ans += mp[i] * c[i][1];
  }
  P(ans);


  // rep (i, 10) {
  //   rep (j, 10) {
  //     cout << c[i][j] << " ";
  //   }
  //   cout << endl;
  // }



  return 0;
}

