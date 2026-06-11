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
  int n, k;
  cin >> n >> k;
  int index = 0;
  rep (i, n) {
    int tmp;
    cin >> tmp;
    if (tmp == 1) index = i;
  }

  int ans    = 0;
  int hidari = index;
  int migi   = n - index - 1;
  if (hidari + 1 < k) {
    migi -= (k - hidari - 1);
    ans++;
    if (migi <= 0) {
      P(ans);
      return 0;
    }
    hidari = 0;
  } else if (migi + 1 < k) {
    hidari -= (k - migi - 1);
    ans++;
    if (hidari <= 0) {
      P(ans);
      return 0;
    }
    migi = 0;
  }
  // cout << "hidari: " << hidari << " / migi: " << migi << endl;
  ans += (hidari + migi) / (k - 1);
  // ans += hidari / (k - 1);
  // ans += migi  / (k - 1);
  // if (hidari % (k - 1) != 0) ans++;
  // if (migi % (k - 1) != 0) ans++;

  if ((hidari + migi) % (k - 1) != 0) ans++;
  P(ans);
  return 0;
}

