#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define erep(i,a,n) for(int i = a;i<=n;i++)
typedef long long ll;
#define int long long
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define P pair<int,int>
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

struct Sieve{
  int n;
  vector<int> f,primes;
  Sieve(int n=1):n(n),f(n+1){
    f[0] = f[1] = -1;
    for(int i = 2; i <= n;++i){
      if(f[i]) continue;
      primes.push_back(i);
      f[i] = i;
      for(int j = i*i;j <= n;j += i){
        if(!f[j]) f[j] = i;
      }
    }
  }
  bool isPrime(int x){return f[x] == x;}
  vector<int> factorList(int x){
    vector<int> res;
    while(x != 1){
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  vector<P> factor(int x){
    vector<int> fl = factorList(x);
    if(fl.size() == 0) return {};
    vector<P> res(1,P(fl[0],0));
    for(int p:fl){
      if(res.back().first == p){
        res.back().second++;
      }
      else{
        res.emplace_back(p,1);
      }
    }
    return res;
  }
};

signed main(){
  int n;
  cin >> n;
  vint cnt(110);
  Sieve tree(150);
  rep(i,1,n+1){
    auto m = tree.factor(i);
    for(auto p : m){
      cnt[p.first] += p.second;
    }
  }
  // rep(i,0,n) cout << cnt[i] << endl;
  vint ans(100);
  for(auto p:cnt){
    if(p >=74 ) ans[74]++;
    if(p >=24 ) ans[24]++;
    if(p >=14 ) ans[14]++;
    if(p >=4 ) ans[4]++;
    if(p >=2 ) ans[2]++;
  }
  int ANS = 0;
  ANS += ans[74];
  // [2]に[24]の分も含まれているのでそれを引いている
  ANS += ans[24]*(ans[2] - 1);
  ANS += ans[14]*(ans[4] - 1);
  // まずは[2]のみを満たしているものから計算
	ANS += (ans[4] * (ans[4] - 1)) / 2 * (ans[2] - ans[4]);
  // 最後に[4]を満たしているものから考える
	ANS += (ans[4] * (ans[4] - 1)) / 2 * (ans[4] - 2);
  cout << ANS << endl;
}