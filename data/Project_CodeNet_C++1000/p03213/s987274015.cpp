#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) int(x.size())

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const double PI=3.14159265358979323846;

int mod = 1e9+7;
const long long INF = 1LL<<60;

struct Sieve {
  int n;
  vector<int> f, primes;
  Sieve(int n=1):n(n), f(n+1) {
    f[0] = f[1] = -1;
    for (ll i = 2; i <= n; ++i) {
      if (f[i]) continue;
      primes.push_back(i);
      f[i] = i;
      for (ll j = i*i; j <= n; j += i) {
        if (!f[j]) f[j] = i;
      }
    }
  }
  bool isPrime(int x) { return f[x] == x;}
  vector<int> factorList(int x) {
    vector<int> res;
    while (x != 1) {
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  vector<P> factor(int x) {
    vector<int> fl = factorList(x);
    if (fl.size() == 0) return {};
    vector<P> res(1, P(fl[0], 0));
    for (int p : fl) {
      if (res.back().first == p) {
        res.back().second++;
      } else {
        res.emplace_back(p, 1);
      }
    }
    return res;
  }
};

int main(){
  int N;
  cin >> N;

  Sieve sieve(101);

  vector<int> cnt(101);
  for(int i=1; i<=N; i++){
    vector<P> res = sieve.factor(i);
    for(P p: res){
      int num = p.first;
      int freq = p.second;
      cnt[num] += freq;
    }
  }

  int ans = 0;

  int over2 = 0;
  int over4 = 0;
  int over14 = 0;
  int over24 = 0;
  int over74 = 0;
  rep(i, 101){
    if(cnt[i] >= 2) over2++;
    if(cnt[i] >= 4) over4++;
    if(cnt[i] >= 14) over14++;
    if(cnt[i] >= 24) over24++;
    if(cnt[i] >= 74) over74++;
  }
  // 1 * 75
  ans += over74;
  // 3 * 25
  ans += over24 * (over2 - 1);
  // 5 * 15
  ans += over14 * (over4 - 1);
  // 3 * 5 * 5
  ans += over4 * (over4-1) * (over2 - 2) / 2;


  cout << ans << endl;
  
  return 0;
}
