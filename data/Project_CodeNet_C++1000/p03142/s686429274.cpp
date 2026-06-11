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
#define p_no() p("NO")
#define SZ(x) ((int)(x).size())
#define SORT(A) sort(ALL(A))
#define RSORT(A) sort(ALL(A), greater<ll>())

void no(){p_no(); exit(0);}
void yes(){p_yes(); exit(0);}

const ll mod = 1e9 + 7;
const ll inf = 1e18;

VI topological_sort(VV& G){
    ll N = G.size();
    debug(N);
    debug(G);
    
    // 入次数
    VI IN(N, 0);
    rep(i, N){
        for(ll to : G[i]){
            IN[to]++;
        }
    }

    stack<ll> st; // 入次数0のものを入れる
    rep(i, N){
        if(IN[i]==0) st.push(i);
    }

    VI ret;
    while(!st.empty()){
        ll i = st.top();
        st.pop();
        ret.push_back(i);
        for(ll to : G[i]){
            IN[to]--;
            if(IN[to]==0){
                st.push(to);
            }
        }
    }

    // 成功したか確認
    for(ll in : IN){
        if(in!=0){
            // 失敗（DAGじゃなかった）
            VI empty_vector;
            debug("not DAG");
            return empty_vector;
        }
    }
    // 正常の戻り値
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll N, M;
    cin >> N >> M;

    VV G(N);
    VV IN(N); // 親たち

    rep(i, N+M-1){
      ll a, b;
      cin >> a >> b;
      a--; b--;
      debug(a, b);
      G[a].push_back(b);
      // a -> b
      IN[b].push_back(a);
    }

    VI res = topological_sort(G);
    VI I(N); // 逆引き
    rep(i, N){
      ll a = res[i];
      I[a] = i;
    }
    debug(res);
    debug(I);

    rep(i, N){
      ll new_i = I[i];
      if(new_i==0){
        p(0);
        continue;
      }
      // そいつに刺さってくるやつら
      ll ma = 0;
      for(ll par : IN[i]){
        ll new_p = I[par];
        chmax(ma, new_p);
      }
      // 元の世界に戻す
      ll ans = res[ma];
      p(ans+1);
    }

    return 0;
}