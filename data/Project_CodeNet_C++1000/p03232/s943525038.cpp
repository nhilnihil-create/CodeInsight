#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = 1e+14;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(ll i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second

void Yes(){
	cout<<"Yes"<<endl;
	exit(0);
}
 
void No(){
	cout<<"No"<<endl;
	exit(0);
}

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll extgcd(ll a, ll b, ll& x, ll & y) {
    ll d = a;
    if(b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1; y = 0;
    }
    return d;
}

bool is_prime(int n) {
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
        return n != 1;
    }
}

vector<int> divisor(int n) {
    vector<int> res;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            res.push_back(i);
            if(i * i != n) res.push_back(n / i);   
        }
    }
}

map<int, int> prime_factor(int n) {
    map<int, int> res;
    for(int i = 2; i * i <+ n; i++) {
        while(n % i == 0) {
            res[i] ++;
            n /= i;
        }
    }
    if(n != 1) res[n] = 1;
    return res;
}

ll mod_inverse(ll a, ll m) {
    ll x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N; cin >> N;
  ll A[100100]; rep(i, N) cin >> A[i];
  ll inverse[100100];
  rep(i, N) {
      inverse[i] = mod_inverse(i + 1, mod);
  }
  ll imos[100100];
  imos[0] = 0;
  rep(i, N) {
    imos[i + 1] = imos[i] + inverse[i];
    imos[i + 1] %= mod;
  }
  ll ans = 0;
  rep(i, N) {
      ll res = imos[N - i] - imos[0] + imos[i + 1] - imos[1];
      res %= mod;
      res *= A[i];
      res %= mod;
      ans += res;
      ans %= mod;
  }
  rep1(i, N) {
      ans *= i;
      ans %= mod;
  }
  cout << ans << endl;
  return 0;
}