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
  ll r, g, b, n;
  cin >> r >> g >> b >> n;

  ll sum = 0; ll count = 0;
  rep(i, 3001) {
      rep(j, 3001) {
          ll rem = r*i + g*j;
          if (n >= rem && (n-rem)%b == 0) count++;
            //   cout << i << " " << j << " " << n-i-j << " " << endl;
      }
  }

  cout << count << endl;
  return 0;
}