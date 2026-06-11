#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int n;
vector<pair<ll, ll>> prime_factorize(ll n) {
  vector<pair<ll, ll>> res;
  for(int i = 2; i * i <= n; ++i) {
    if(n % i) continue;
    res.emplace_back(i, 0);
    while (!(n % i)) {
      res.back().second++;
      n /= i;
    }
  }
  if(n != 1) res.emplace_back(n, 1);
  return res;
}

map<ll, int> sisuu;

ll rec(map<ll, int>::iterator p, ll mul) {
  if(p == sisuu.end()) {
    if(mul == 1) return 1;
    else return 0;
  }
  ll res = 0;
  for(int i = 0; i <= p->second; ++i) {
    if(mul % (i + 1)) continue;
    res += rec(++p, mul / (i + 1));
    --p;
  }
  return res;
}

int main(){
  cin >> n;
  for(int i = 2; i <= n; ++i) {
    auto ps = prime_factorize(i);
    for (auto it : ps) sisuu[it.first] += it.second;
  }
  cout << rec(sisuu.begin(), 75) << endl;
}