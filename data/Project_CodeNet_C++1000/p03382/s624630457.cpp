#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
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

ll n;
ll a[MAX_N];

int main(){
  cin >> n;
  REP(i, n) cin >> a[i];
  ll mav = 0;
  int mai;
  REP(i, n) {
    if(mav < a[i]) {
      mav = a[i];
      mai = i;
    }
  }
  ll hd = INFll;
  int hi;
  REP(i, n) {
    if(i == mai) continue;
    if(hd > abs(a[i] - mav / 2)) {
      hd = abs(a[i] - mav / 2);
      hi = i;
    }
  }
  cout << mav << " " << a[hi] << endl;

  return 0;
}
