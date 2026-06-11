#include <bits/stdc++.h>
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,a,b)for(int i=(int)(a);(i)<(int)(b);i++)

typedef unsigned long long ull;
typedef long long ll;

const int INF = 1001001001;
const ll MOD = 1e9 + 7;

using namespace std;
using P = pair<int,int>;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }

int main() {
  ll n; cin >> n;

  string s; map<char, ll> count;
  rep(i, n) {
      cin >> s;
      if (s[0] == 'M' || s[0] == 'A' || 
          s[0] == 'R' || s[0] == 'C' || s[0] == 'H')
      {
          count[s[0]] += 1;
      }
  }

  char patterns[5] = { 'M', 'A', 'R', 'C', 'H' };
  ll ans = 0; ll sum = 0;
  rep(i, 3) {
      for (ll j = i+1; j < 4; j++)
      {
          /* code */
          for (ll k = j+1; k < 5; k++)
          {
              ans += count[patterns[i]] * count[patterns[j]] * count[patterns[k]];
          }
      }
      
  }

  cout << ans << endl;
  return 0;
}