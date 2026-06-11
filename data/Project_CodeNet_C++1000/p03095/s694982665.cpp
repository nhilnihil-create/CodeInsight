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

static const long long MOD = 1000000007;
static const long long LINF = (long long)(1e18+99);
static const int INF = 1000000099;

ll n,  c[30], ans = 1;
string s;
 //解説あり
int main(void) {
  cin >> n >> s;
  rep(i, 0, n) c[s[i]-'a']++;
  
  rep(i, 0, 26){
    if (c[i]>0) ans *= c[i]+1;
    ans %= MOD;
  }
  
    cout << ans-1 << endl;
    return 0;
}
