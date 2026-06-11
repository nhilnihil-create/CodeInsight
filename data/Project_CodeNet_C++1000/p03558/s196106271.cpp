#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

const double pi = 3.141592653589793238462643383279;
using namespace std;
using namespace __gnu_pbds;
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
 
 
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
 
//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007
 
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)

const long double EPS = 1e-6, PI = acos((long double)-1);

//ここから編集
ll modPow(ll x, ll n, ll mod = MOD){
    ll res = 1;
    while(n){
        if(n&1) res = (res * x)%mod;
 
        res %= mod;
        x = x * x %mod;
        n >>= 1;
    }
    return res;
}

ll dist[101010];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  int K; cin >> K;
  REP(j,101010)dist[j] = INT_MAX;

  queue<pair<ll,ll>> q;
  ll ans = (1LL<<60);
  for(int i=1; i<10; i++){
    if(dist[i%K] > i){
      dist[i%K] = i;
      if(i%K == 0){
        ans = min(ans, (ll)i);
      }
      q.push(make_pair(1, i%K));
      
    }
  }

  while(q.size()){
    auto p = q.front();
    q.pop();


    ll len = p.first;
    if(len > 101010) break;
    ll amari = p.second;
    if(dist[amari]>= ans) continue;

    for(ll i=0; i<10; i++){
      ll nx = (amari*10 + i) % K;
      if(dist[nx] > dist[amari] + i){
        dist[nx] = dist[amari] + i;

        q.push(make_pair(len+1, nx));
      }
      if(nx == 0){
          ans = min(ans, dist[nx]);
        }
    }
  }

  cout << ans << endl;
  return 0;
}