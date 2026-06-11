#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<ll,ll>;

// Sieve of Eratosthenes
// https://youtu.be/UTVg7wzMWQc?t=2774
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
  vector<pair<ll,int>> factor(ll x) {
    vector<pair<ll,int>> res;
    for (int p : primes) {
      int y = 0;
      while (x%p == 0) x /= p, ++y;
      if (y != 0) res.emplace_back(p,y);
    }
    if (x != 1) res.emplace_back(x,1);
    return res;
  }
};

int getAllCase(vector<int> &a,int n){
  int retVal = 0;
  for(int t:a){
    if(t>=n){
      retVal++;
    }
  }
  return retVal;
}

int main() {
    ll N;
    cin >> N;
    Sieve sieve = Sieve(N);
    map<ll,ll> mp;
    for(int i=2;i<=N;i++){
      vector<P> factors = sieve.factor(i);
      for(P p:factors){
        mp[p.first] += p.second;
      }
    }
    vector<int> num;
    for(auto itr = mp.begin();itr != mp.end();++itr){
      if(itr->second>=2){
        num.push_back(itr->second);
      }
    }
    ll ans =0;
      
      int n3 = getAllCase(num,2);
      int n5 = getAllCase(num,4);
      int n15 = getAllCase(num,14);
      int n25  = getAllCase(num,24);
      int n75 = getAllCase(num,74);
      //3,5,5の場合
      ans += ((n5*(n5-1))/2)*(n3-2);
      //3,25の場合
      ans += n25*(n3-1);
      //5,15の場合
      ans += n15*(n5-1);
      //75の場合
      ans += n75;
      cout << ans << endl;

    return 0;
}