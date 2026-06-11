#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<ll>;
using VV = vector<VI>;
using VS = vector<string>;
using PII = pair<ll, ll>;

// tourist set
template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << '\n'; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
// tourist set end

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,b) FOR(i, 0, b)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<'\n'
#define p2(s, t) cout << (s) << " " << (t) << '\n'
#define br() p("")
#define pn(s) cout << (#s) << " " << (s) << '\n'
#define p_yes() p("YES")
#define p_no() p("NO")
#define SZ(x) ((int)(x).size())
#define SORT(A) sort(ALL(A))
#define RSORT(A) sort(ALL(A), greater<ll>())
#define MP make_pair

void no(){p_no(); exit(0);}
void yes(){p_yes(); exit(0);}

const ll mod = 998244353;
const ll inf = 1e18;
const double PI = acos(-1);

const int N_MAX = 300010;
ll Per[N_MAX] = {}; // n!
ll Per_inv[N_MAX] = {}; //(n!)^-1

ll nCr(ll n, ll r){
    if(n<r) return 0;
 
    if (n == r || r == 0)
        return 1;
    else
        return Per[n] * Per_inv[n-r] % mod * Per_inv[r] % mod;  
}
 
// a^b mod p
ll mod_pow(ll a, ll b){
    if(b==0) return 1;
 
    // 肩が奇数
    if(b%2==1){
        return a * mod_pow(a, b-1) % mod;
    }
    else{
        return mod_pow(a*a % mod, b/2) % mod;
    }
}

void prepare_nCr(){
    Per[0] = 1;
    Per_inv[0] = 1;

    // nCr高速化準備
    Per[1] = 1;
    FOR(i, 2, N_MAX){
        Per[i] = i * Per[i-1] % mod;
    }
    Per_inv[1] = 1;
    FOR(i, 2, N_MAX){
        Per_inv[i] = mod_pow(Per[i], mod-2);
    }
}

ll nHr(ll n, ll r){
  return nCr(n-1+r, n-1);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll N,A,B,K;
    cin >> N>>A>>B>>K;

    prepare_nCr();

    ll ans = 0;
    rep(r, N+1){
      ll rest = K-A*r;
      if(rest<0){
        continue;
      }else if(rest%B!=0){
        continue;
      }
      ll b = rest/B;
      debug(r, b);

      ans += nCr(N, r) * nCr(N, b) % mod;
      ans %= mod;
    }
    p(ans);
    
    return 0;
}