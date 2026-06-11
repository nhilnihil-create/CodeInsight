#include <bits/stdc++.h>
#define FOR(i, k, n) for(int i = (k); i < (n); i++)
#define FORe(i, k, n) for(int i = (k); i <= (n); i++)
#define FORr(i, k, n) for(int i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(int i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const int INF = 1001001001;
ll N;
map<ll, ll> sisuu;

vector<P> prime_factorize(ll n){
  vector<P> ret;
  for(ll i = 2; i*i <= n; i++){
    if(n%i) continue;
    int num = 0;
    while(n%i == 0){
      n /= i;
      num++;
    }
    ret.emplace_back(P(i, num));
  }
  if(n != 1) ret.emplace_back(P(n, 1));
  return ret;
}

ll rec(map<ll, ll>::iterator itr, ll mul){
  if(itr == sisuu.end()) return (mul == 1) ? 1 : 0;

  ll ret = 0;
  REP(i, itr->second+1){
    if(mul%(i+1)) continue;
    ret += rec(++itr, mul/(i+1));
    itr--;
  }
  return ret;
}

int main(void){
  cin >> N;
  FORe(i, 2, N){
    auto pf = prime_factorize(i);
    for(P p : pf) sisuu[p.first] += p.second;
  }
  cout << rec(sisuu.begin(), 75) << endl;
  return 0;
}