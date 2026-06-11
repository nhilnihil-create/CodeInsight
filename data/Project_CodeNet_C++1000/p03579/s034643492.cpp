#include <bits/stdc++.h>
#define FOR(v, a, b) for(int v = (a); v < (b); ++v)
#define FORE(v, a, b) for(int v = (a); v <= (b); ++v)
#define REP(v, n) FOR(v, 0, n)
#define REPE(v, n) FORE(v, 0, n)
#define REV(v, a, b) for(int v = (a); v >= (b); --v)
#define ALL(x) (x).begin(), (x).end()
#define ITR(it, c) for(auto it = (c).begin(); it != (c).end(); ++it)
#define RITR(it, c) for(auto it = (c).rbegin(); it != (c).rend(); ++it)
#define EXIST(c,x) ((c).find(x) != (c).end())
#define LLI long long int
#define fst first
#define snd second
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#ifndef M_E
#define M_E 2.71828182845904523536
#endif
#ifdef DEBUG
#include <boost/core/demangle.hpp>
#define dump(x) cerr << "L" << __LINE__ << ": in " << __PRETTY_FUNCTION__ << " \e[32;1m" << boost::core::demangle(typeid(x).name()) << "\e[37m" << " " << (#x) << " = " << (x) << "\e[m" << endl;
#else
#define dump(x)
#endif
#define pln(x) cout << (x) << endl
#define gcd __gcd

using namespace std;
template <class T> constexpr T lcm(T m, T n){return m*n/gcd(m,n);}

template <typename T> using V = vector<T>;
template <typename T, typename U> using P = pair<T,U>;
template <typename I> void join(ostream &ost, I s, I t, string d=" "){for(auto i=s; i!=t; ++i){if(i!=s)ost<<d; ost<<*i;}ost<<endl;}
template <typename T> istream& operator>>(istream &is, vector<T> &v){for(auto &a : v) is >> a; return is;}
template <typename T, typename U> istream& operator>>(istream &is, pair<T,U> &p){is >> p.first >> p.second; return is;}

template <typename Iter> ostream& out_container(ostream &os, Iter first, Iter last){
  os << "{"; auto itr = first; while(itr != last){if(itr != first) os << ","; os << *itr; ++itr;} os << "}"; return os;
}

template <typename T> ostream& operator<<(ostream &os, const vector<T> &c){return out_container(os,ALL(c));}
template <typename T> ostream& operator<<(ostream &os, const deque<T> &c){return out_container(os,ALL(c));}
template <typename T> ostream& operator<<(ostream &os, const set<T> &c){return out_container(os,ALL(c));}
template <typename T> ostream& operator<<(ostream &os, const unordered_set<T> &c){return out_container(os,ALL(c));}
template <typename T, typename U> ostream& operator<<(ostream &os, const map<T,U> &c){return out_container(os,ALL(c));}
template <typename T, typename U> ostream& operator<<(ostream &os, const unordered_map<T,U> &c){return out_container(os,ALL(c));}
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T,U> &p){os << "(" << p.first << "," << p.second << ")"; return os;}

template <typename T> T& chmin(T &a, const T &b){return a = min(a,b);}
template <typename T> T& chmax(T &a, const T &b){return a = max(a,b);}

bool is_bipartite_graph(vector<vector<int>> &graph, LLI &a, LLI &b){
  vector<int> check(graph.size(), -1);
  vector<bool> visit(graph.size(), false);
  stack<int> st;

  st.push(0);
  check[0] = 0;

  while(!st.empty()){
    auto cur = st.top(); st.pop();
    if(visit[cur]) continue;
    visit[cur] = true;

    for(auto next : graph[cur]){
      if(check[next] == check[cur]) return false;

      if(check[next] == -1){
	check[next] = (check[cur]==0 ? 1 : 0);
      }

      st.push(next);
    }
  }

  a = b = 0;
  for(auto x : check) if(x) ++a; else ++b;
  
  return true;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  LLI N,M;
  while(cin >> N >> M){
    vector<vector<int>> graph(N);
    REP(i,M){
      int a,b; cin >> a >> b;
      --a, --b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    LLI a,b;
    if(is_bipartite_graph(graph,a,b)){
      cout << a*b-M << endl;
    }else{
      cout << N*(N-1)/2-M << endl;
    }
  }
  
  return 0;
}
