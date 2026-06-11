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
  string s;
  vl alpha(26);
  rep(_, n) {
    cin >> s;
    alpha[s[0]-'A']++;
  }
  
  string MARCH = "MARCH";
  vl cnt(5);
  rep(i, 5) cnt[i] = alpha[MARCH[i]-'A'];
  
  ll ans=0;
  vector<bool> choose3 = {0,0,1,1,1};
  do {
    ll num=1;
    rep(i, 5) if(choose3[i]) num *= cnt[i];
    ans += num;
  }while (next_permutation(all(choose3)));
  
  cout << ans << newl;
  return 0;
}