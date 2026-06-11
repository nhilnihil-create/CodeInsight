#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<char> vc;
typedef queue<ll> ql;
typedef deque<ll> dql;
typedef priority_queue<ll/*, vl, greater<ll>*/> pql; //降順(/*昇順*/)
typedef set<ll> sl;
typedef pair<ll, ll> pl;
typedef vector<vl> vvl;
typedef vector<pl> vpl;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define rep2(i, n) for(ll i = 1; i <= ll(n); i++)
//#define rep(i, k, n) for(ll i = k-1; i < ll(n); i++)
//#define rep2(i, k, n) for(ll i = k; i <= ll(n); i++)
#define all(v) (v).begin(), (v).end()
bool chmin(ll &a, ll b) {if(b < a) {a = b; return 1;} return 0;}
bool chmax(ll &a, ll b) {if(b > a) {a = b; return 1;} return 0;}
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;
const ll MAX = 1e9;
const char newl = '\n';

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;
  vl a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  
  ll ans=0;
  vl d(n);
  rep(i, n) d[i]=a[i]-b[i];
  sort(all(d));
  ll lack=0;
  rep(i, n) {
    if(d[i]<0) {lack+=d[i]; ans++;}
    else break;
  }
  ll k=n-1, add=0;
  while(add+lack<0){
    if(d[k]<0) {cout << "-1" << newl; return 0;}
    add+=d[k];
    k--; ans++;
  }
  cout << ans << newl;
  return 0;
}