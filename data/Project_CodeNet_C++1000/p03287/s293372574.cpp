#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
template <typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template <typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int INT_INF = 1 << 30;
#define MOD 1000000007LL

ll ncr(ll n, ll r){
  if(n < r) return 0;
  if(r > n-r) r = n-r;

  ll a = 1, b = 1;
  for(int i = 0; i < r; i++){
    a *= (n - i);
  }
  for(int i = 0; i < r; i++){
    b *= (i + 1);
  }
  return a/b;
}

int main(){
  ll N, M;
  cin >> N >> M;
  vll A(N);
  for(int i = 0; i < N; i++){
    cin >> A.at(i);
  }
  vll sum(N+1, 0);
  for(int i = 0; i < N; i++){
    sum.at(i+1) = sum.at(i) + A.at(i); 
  }
  map<int, ll> ma;
  for(int i = 0; i < N+1; i++){
    int n = sum.at(i) % M;
    if(!ma.count(n)) ma[n] = 1LL;
    else ma.at(n)++;
  }
  ll ans = 0LL;
  for(auto ite = ma.begin(); ite != ma.end(); ite++){
    ll n = ite -> second;
    ans += ncr(n, 2LL);
  }
  cout << ans << endl;
}