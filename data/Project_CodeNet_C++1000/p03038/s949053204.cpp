#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef queue<ll> ql;
typedef deque<ll> dql;
typedef priority_queue<ll> pql;
typedef set<ll> sl;
typedef pair<ll, ll> pl;
typedef pair<pl, ll> ppl;
typedef vector<vl> vvl;
typedef vector<pl> vpl;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define rep2(i, k, n) for(ll i = ll(k); i <= ll(n); i++)
#define rep3(i, n, k) for(ll i = ll(n); i >= ll(k); i--)
#define all(v) (v).begin(), (v).end()
ll mod(ll a, ll b) {if(b == 0) return 0; return (a % b + b) % b;}
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
  
  ll n, m, a, b, c;
  cin >> n >> m;

  map<ll, ll> cnt;
  vl num;

  rep(_, n) {
    cin >> a;
    cnt[a]++;
    num.push_back(a);
  }

  rep(_, m) {
    cin >> b >> c;
    cnt[c] += b;
    num.push_back(c);
  }

  sort(all(num), greater<ll>());

  ll ans=0;
  rep(i, num.size()) {
    if(n - cnt[num[i]] >= 0) {
      ans += num[i] * cnt[num[i]];
      n -= cnt[num[i]];
      cnt[num[i]] = 0;
    }else {
      ans += num[i] * n;
      n = 0;
      break;
    }
  }

  cout << ans << newl;
  return 0;
}