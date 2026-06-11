#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define rep(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define REP(i,num,n) for(ll i=num, i##_len=(n); i<i##_len; ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define print(x) cout << (x) << endl;
#define sz(x) int(x.size())
 
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
const ll LLINF = 1LL<<60;
const int INF = 1<<29;
const int MOD = 1000000007;
 
void add(long long &a, long long b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
 
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

vector<pair<long long, long long> > prime_factorize(long long n) { //素因数分解、pairのfirstに底、secondに底の何乗
   vector<pair<long long, long long> > res;
   for (long long p = 2; p * p <= n; ++p) {
       if (n % p != 0) continue;
       int num = 0;
       while (n % p == 0) { ++num; n /= p; }
       res.push_back(make_pair(p, num));
   }
   if (n != 1) res.push_back(make_pair(n, 1));
   return res;
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(10);
    int N;
    ll P;
    cin >> N >> P;
    auto fac = prime_factorize(P);
    ll ans = 1;
    for(auto p : fac){
      rep(j, p.second/N) ans *= p.first;
    }
    print(ans);
}