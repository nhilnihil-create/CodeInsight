//解説
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()

using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;
static const int MAX = 1000005;

int n;
vector<int> v;

int main(void) {
  cin >> n;
  rep(i,0,n) {
    int d;
    cin >> d;
    v.pb(min(d, 24-d));
  }
  sort(v.bg, v.en);
  rep(i,0,n) {
    if (i%2==1) v[i] = 24 - v[i];
  }
  v.pb(0); v.pb(24);
  
  sort(v.bg, v.en);
  int mn = 100;
  rep(i,0,n+1) mn = min(v[i+1]-v[i], mn);
  
  cout << mn << endl;
  
    return 0;
}

