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

  string s;
  cin >> s;
  
  if(s.size()<26) {
    vector<char> cha;
    rep(i, s.size()) cha.push_back(s[i]);
    rep(i, 26) if(!count(all(cha), char('a'+i))) {s+=char('a'+i); break;}
    cout << s << newl;
    return 0;
  }
  
  if(s.size()==26) {
    ll k=0;
    vector<char> cha={s[25]};
    for(;k<25;k++) {
      if(s[24-k]<s[25-k]) {
        sort(all(cha));
        s[24-k]=cha[upper_bound(all(cha), s[24-k])-cha.begin()];
        break;
      }
      else cha.push_back(s[24-k]);
    }
    if(cha.size()==26) cout << -1 << newl;
    else cout << s.substr(0, 25-k) << newl;
    return 0;
  }
}