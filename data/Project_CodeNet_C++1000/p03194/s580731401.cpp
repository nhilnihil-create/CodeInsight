#include<bits/stdc++.h>
using namespace std;
// g++ Main.cpp -std=gnu++1y -O2 -I/opt/boost/gcc/include -o main && ./main
// g++ Main.cpp -std=gnu++1y -O2 -I/opt/boost/gcc/include -o main && ./main

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vll = vector<vl>;
using vii = vector<vi>;
using pii = pair<int, int>;

using vc = vector<char>;
using vcc = vector<vc>;
using vb = vector<bool>;
using vbb = vector<vb>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using vd = vector<double>;
using vdd = vector<vd>;

#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i, a, b) for(int (i) = a; (i) < (b);(i)++)
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a > b) ? b : a)

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


const int MOD = 1e9 + 7;

vector<pii> prime_factorization(int n){ // 素因数分解をしたvector<素数, 指数>を返す
  vector<pii> res;
  int tmp, root_n = floor(sqrt(n));
  if(n % 2 == 0){
    tmp = 1;
    n /= 2;
    while(n % 2 == 0){
      n /= 2;
      tmp++;
    }
    res.push_back(make_pair(2, tmp));
  }
  ll i = 3;
  while(i <= root_n && i <= n){
    if(n % i == 0){
      tmp = 1;
      n /= i;
      while(n % i == 0){
        n /= i;
        tmp++;
      }
      res.push_back(make_pair(i, tmp));
    }
    i += 2;
  }
  if(n != 1) res.push_back(make_pair(n, 1));
  return res;
}
vector<pli> prime_factorization(ll n){ // 素因数分解をしたvector<素数, 指数>を返す
  vector<pli> res;
  int tmp, root_n = floor(sqrt(n));
  if(n % 2 == 0){
    tmp = 1;
    n /= 2;
    while(n % 2 == 0){
      n /= 2;
      tmp++;
    }
    res.push_back(make_pair(2, tmp));
  }
  ll i = 3;
  while(i <= root_n && i <= n){
    if(n % i == 0){
      tmp = 1;
      n /= i;
      while(n % i == 0){
        n /= i;
        tmp++;
      }
      res.push_back(make_pair(i, tmp));
    }
    i += 2;
  }
  if(n != 1) res.push_back(make_pair(n, 1));
  return res;
}

// n は 2以上の素数表を返す
vb Primes(int n){
  vector<bool> res(n + 1, true);
  res.at(0) = false; res.at(1) = false;
  for(int i = 2; i <= sqrt(n); i++){
    if(res.at(i)){
      for(int j = 2 * i; j <= n; j += i){
        res.at(j) = false;
      }
    }
  }
  return res;
}
// ===================================================


ll power(ll a, int n){
  if(n == 0) return 1;
  ll prev = power(a, n / 2);
  if((n & 1) == 0) return prev * prev;
  return a * prev * prev;
}

int main(){
  ll n, p, res = 1; cin >> n >> p;
  vector<pli> v = prime_factorization(p);
  for(pli x : v){
    res *= power(x.first, x.second / n);
  }
  cout << res << endl;
  return 0;
}