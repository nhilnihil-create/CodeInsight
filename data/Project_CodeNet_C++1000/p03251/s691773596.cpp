#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <set>
using namespace std;
typedef long long int ll;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define yes cout << "yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define no cout << "no" << endl

const int INF = 1001001001;
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
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  int maxN = -1000;
  int minN = 1000;
  int maxM = -1000;
  int minM = 1000;
  int tmp = 0;
  rep (i, n) {
    cin >> tmp;
    maxN = max(tmp, maxN);
    minN = min(tmp, minN);
  }
  rep (i, m) {
    cin >> tmp;
    minM = min(tmp, minM);
    maxM = max(tmp, maxM);
  }
  if (minM > maxN && maxN > x && minM <= y) P("No War");
  else P("War");

  return 0;
}

