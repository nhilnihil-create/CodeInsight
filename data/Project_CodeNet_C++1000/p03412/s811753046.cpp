#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
#include <string.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

double EPS = 1e-9;
int INFi = 1000000005;
long long INFll = 1000000000000000005ll;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
ll MOD = 1000000007;

const int MAX_N = 200000;
int n;
ll a[MAX_N], b[MAX_N];

int main(){
  cin >> n;
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> b[i];

  ll moda[n], modb[n];
  ll ans = 0;

  REP(k, 29) {
    REP(i, n) {
      moda[i] = a[i] % (2 << k);
      modb[i] = b[i] % (2 << k);
    }
    sort(modb, modb + n);

    ll num_1 = 0;
    REP(i, n) {
      num_1 += ((lower_bound(modb, modb + n, 2 * (1 << k) - moda[i] ) - lower_bound(modb, modb + n, (1 << k) - moda[i])) + (lower_bound(modb, modb + n, 4 * (1 << k) - moda[i] ) - lower_bound(modb, modb + n, 3 * (1 << k) - moda[i]))) % 2;
    }
    ans += num_1 % 2 * (1 << k);
  }

  cout << ans << endl;

  return 0;
}
