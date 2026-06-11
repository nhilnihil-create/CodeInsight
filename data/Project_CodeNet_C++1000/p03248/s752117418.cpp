#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<ll>;
using VV = vector<VI>;
using VS = vector<string>;

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
#define p_no() p("-1")
#define SZ(x) ((int)(x).size())
#define SORT(A) sort(ALL(A))
#define RSORT(A) sort(ALL(A), greater<ll>())

void no(){p_no(); exit(0);}
void yes(){p_yes(); exit(0);}

const ll mod = 1e9 + 7;
const ll inf = 1e18;
const double PI = acos(-1);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    string s; cin >> s;
    ll N = s.size();

    if(s[N-1]=='1' || s[0]=='0'){
      no();
    }

    rep(i, N-1){
      ll id = i+1;
      ll id2 = N-id;
      if(s[i]!=s[id2-1]){
        no();
      }
    }

    s[N-1] = '1';
    ll j = N-1;
    VV G(N);
    for(int i=N-2; i>=0; i--){
      if(s[i]=='1'){
        // i to jで辺をはる
        G[i].push_back(j);
        //G[j].push_back(i);
        j = i;
      }
      else{
        G[i].push_back(j);
        //G[j].push_back(i);
      }
    }

    ll cnt = 0;
    rep(i, N){
      cnt += G[i].size();
    }
    if(cnt!=N-1){
      p("error");
    }

    rep(i, N){
      for(ll to : G[i]){
        p2(i+1, to+1);
      }
    }

    

    
    return 0;
}