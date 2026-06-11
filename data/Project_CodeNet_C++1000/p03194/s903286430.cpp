#define ioFix ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

long long madd(long long x, long long y, long long modulo) {
  return (x + y) % modulo;
}

long long mmult(long long x, long long y, long long modulo) {
  return (x * y) % modulo;
}

long long mpow(long long base, long long exponent, long long modulo) {
  long long res = 1;
  for(int i = 0; i < exponent; i++)
    res = (res * base) % modulo;
  return res;
}

long long mfac(long long n, long long modulo) {
  long long res = 1;
  for(int i = 2; i <= n; i++)
    res = (res * i) % modulo;
  return res;
}

long long mcomb(long long n, long long k, long long modulo) {
  return mfac(n, modulo) / mmult(mfac(k, modulo), mfac(n-k, modulo), modulo);
}


#define PI (2.0 * acos(0.0))
#define INF (int)1e9
#define LINF (long long)1e18
#define EPS 1e-9

#define ll long long
#define ull unsigned long long

#define pii pair<int, int>
#define pll pair<long long, long long>
#define pdd pair<double, double>
#define pcc pair<char, char>
#define pbb pair<bool, bool>

#define vi vector<int>
#define vvi vector<vector<int>>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vvs vector<vector<string>>

#define REP(n) for(int xix = 0; xix < (n); xix++)
#define FOR(i, from, to) for(int (i) = from; (i) < (to); (i)++)
#define RANGE(i, from, to) for(int (i) = from; (i) <= (to); (i)++)
#define ALL(x) x.begin(),x.end()

#define pb push_back
#define mp make_pair
#define mt make_tuple

#define fillArray(arr, val) std::fill(std::begin(arr), std::end(arr), (val))

#define pow2(x) ((x)*(x))
#define mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))

#define watch(x) cout << (#x) << " is " << (x) << endl
#define watchVector(v) { for(int xvx = 0; xvx < (v).size(); xvx++) { cout << (v)[xvx] << " "; } cout << endl; }
#define watchArray(arr, n) { for(int xax = 0; xax < (n); xax++) { cout << (arr)[xax] << " "; } cout << endl; }
#define watchMatrix(x, rows, cols) for(int r = 0; r < (rows); r++) { for(int c = 0; c < (cols); c++) { cout << (x)[r][c] << " "; } cout << endl; }



#include <bits/stdc++.h>
using namespace std;

ll gcd(ll a, ll b) {
  if(a == 0)
    return b;
  return gcd(b % a, a);
}

int main() {
  ioFix;
  ll N, P;
  cin >> N >> P;

  if(N > log2(P)) {
    cout << 1 << endl;
    return 0;
  }

  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq; // <val, index>
  FOR(i, 0, N)
    pq.push(mp(1, i));

  ll divCounter = 0;
  ll div = 2;
  ll big = P;
  ll sqrtP = ceil(sqrt(P));
  while(big > 1) {
    auto p = pq.top();

    while(big % div != 0 && div <= sqrtP) {
      div++;
    }

    if(div > sqrtP)
      div = big;

    big /= div;
    p.first *= div;
    divCounter++;

    pq.pop();
    pq.push(p);
  }

  if(divCounter < N) {
    cout << 1 << endl;
    return 0;
  }

  ll res = pq.top().first;
  while(!pq.empty()) {
    res = gcd(res, pq.top().first);
    pq.pop();
  }

  cout << res << endl;
}
