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

int n;
ll a, ab, abc, total = 1;
string s;

int main(void) {
  cin >> s;
  n = sz(s);
  rep (i, 0, n) {
    char ch = s[i];
    if (ch=='A') {
      a += total;
      a %= MOD;
    } else if (ch=='B') {
      ab += a;
      ab %= MOD;
    } else if (ch=='C') {
      abc += ab;
      abc %= MOD;
    } else {
      
      abc = abc*3+ab;
      ab = ab*3+a;
      a = a*3+total;
      total *= 3;
      abc %= MOD;
      ab %= MOD;
      a %= MOD;
      total %= MOD;
    }
  
  }
    
    cout << abc % MOD<< "\n";

    return 0;
}

