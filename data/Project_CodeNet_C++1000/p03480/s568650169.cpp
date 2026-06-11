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
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

using namespace std;

typedef long long ll;
typedef long double ld;

static const long long MOD = 1000000007;
static const long long MAX = 100005;

int main(void) {
  string s;
  cin >> s;
  
  int l = 1, r = sz(s)+1;
  while (r-l>1) {
    int m = (r+l)/2;
    bool ok = true;
    for (int i=sz(s)-m; i<m-1; i++) if (s[i]!=s[i+1]) ok = false;
    if (ok) l = m;
    else r = m;
  }
    cout << l << endl;

    return 0;
}
