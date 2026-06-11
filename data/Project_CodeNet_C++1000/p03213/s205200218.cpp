#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int,int> P;

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

//Sieve sieve(1e6);
//auto f = sieve.factor(x);
// for(auto p:f){
//   p.firstは約数
//   p.secondは割れる回数
// }

int main(){
    int n;
    cin >> n;
    Sieve sieve(1e2);
    map<int,int> mp;
    for(int i=1;i<n+1;i++){
        auto f = sieve.factor(i);
        for(auto p:f){
            mp[p.first]+=p.second;
        }
    }
    int c2 = 0;int c4 = 0;int c14 = 0;int c24=0;int c74 =0;
    for(auto p:mp){
        if(p.second>1)c2++;
        if(p.second>3)c4++;
        if(p.second>13)c14++;
        if(p.second>23)c24++;
        if(p.second>73)c74++;
    }
    int ans = 0;
    ans += c4*(c4-1)/2*(c2-2);
    ans += c14*(c4-1);
    ans += c24*(c2-1);
    ans += c74;
    cout << ans << endl;
}