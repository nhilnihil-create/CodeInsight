#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) ((ll)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define prt(x) cout << (x)
#define prtl(x) cout << (x) << endl
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define rrep(i,a,b) for(ll i=a; i>b; i--)
#define mp(a, b) make_pair(a, b)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define debug(v) cout << #v<< ": " << v <<endl;
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using vvc = vector<vector<char>>;
using ll = long long int;
using P = pair<long long int, long long int>;
using Map = map<long long int, long long int>;
ll INF = 1LL<<60;
ll M = 1000000007;

class Radix {
private:
  const char* s;
  int a[128];
public:
  Radix(const char* s = "0123456789ABCDEF") : s(s) {
    int i;
    for(i = 0; s[i]; ++i)
      a[(int)s[i]] = i;
  }
  std::string to(long long p, int q) {
    int i;
    if(!p)
      return "0";
    char t[64] = { };
    for(i = 62; p; --i) {
      t[i] = s[p % q];
      p /= q;
    }
    return std::string(t + i + 1);
  }
  std::string to(const std::string& t, int p, int q) {
    return to(to(t, p), q);
  }
  long long to(const std::string& t, int p) {
    int i;
    long long sm = a[(int)t[0]];
    for(i = 1; i < (int)t.length(); ++i)
      sm = sm * p + a[(int)t[i]];
    return sm;
  }
};


string bist(ll n, ll dig){
    Radix r;
    string p = r.to(n, 2);
    string q = "";
    if(p.size() < dig){
        for(int i=0; i<dig - p.size(); i++){
            q += '0';
        }
        p = q + p;
    }
    return p;
} //［警告］nbaseの呼び出しを先にすること

int main(){
    ll n; string s; cin >> n >> s;
    map<char, ll> m;
    rep(i, 0, n){
        m[s[i]]++;
    }
    ll f = sz(m);
    ll ans = 1;
    for(auto x: m){
        ans *= x.second+1;
        ans %= M;
    }
    prtl(ans - 1);
}

