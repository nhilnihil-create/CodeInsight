///////////////////////////////////////////
// product.cpp created 2018-12-22
// Kamil Tokarski

/*       biblioteczka       */
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// types
typedef long long ll;
typedef long double ld;

#define PR  pair
#define PII pair<ll, ll>
#define PLL pair<ll, ll>

#define VEC vector
#define VL VEC<ll>
#define VI VEC<ll>
#define VPI VEC<PII>
#define VPL VEC<PLL>

// IO
#define fastio ios_base::sync_with_stdio(NULL);cout.tie(NULL);cin.tie(NULL)
#define precise(x) cout << fixed << setprecision(x)

#define read_file(var, file) ifstream var(file)
#define write_file(var, file) ofstream var(file)
#define close_file(var) var.close()

// containers
#define sz(x) (ll)(x.size())
#define all(x) x.begin(), x.end()
/*          koniec          */
const ll MAXN = 1e7 + 1;

struct Div {
  ll value;
  ll alpha;

  bool operator<(const Div &d) const {
    return alpha < d.alpha; 
  }
};
vector<Div> divs;

ll N, P;
ll sito[MAXN];

ll get_pow(ll a, ll b) {
  if(b == 0)
    return 1;
  if(b == 1)
    return a;

  ll val = get_pow(a, b / 2);
  if(b & 1)
    return val * val * a;
  return val * val;
}

int main(int argc, char **argv) {
  fastio;

  cin >> N >> P; 
  if(N == 1) {
    cout << P << endl;
    return 0;
  }

  for(ll i = 2; i < MAXN; ++i) {
    ll alpha = 0;
    while((P % i) == 0)
      ++alpha,
        P /= i;
    if(alpha > 0)
      divs.push_back({i, alpha});
  }

  if(P > 1)
    divs.push_back({P, 1});

  ll gcd = 1;
  for(auto &d : divs) {
    ll reflow = (d.alpha) / N;
    if(reflow == 0)
      continue;

    gcd *= get_pow(d.value, reflow);
  }

  cout << gcd << endl;
  return 0;
}

