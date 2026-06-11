#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define VIEW(x) do {cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;} while(0)
#define ALL(x) (x).begin(),(x).end()
template<class T>bool umax(T &a, const T &b) {if(a<b){a=b;return 1;}return 0;}
template<class T>bool umin(T &a, const T &b) {if(b<a){a=b;return 1;}return 0;}

template<typename A,size_t N,typename T> void FILL(A (&array)[N],const T &val){fill((T*)array,(T*)(array+N),val);}
template<typename T> void FILL(vector<T> &v, const T &x) {fill(v.begin(), v.end(), x);}
template<typename T> void FILL(vector<vector<T>> &v, const T &x) {for(auto &i:v)fill(i.begin(), i.end(), x);}

int n,a,b,c;
int l[8];
const int INF = 1 << 28;

int solve(int t, vector<int> &L) {
  if(L.size() == 0) return INF;
  int ret = INF;
  int N = L.size();
  rep(i, 1, (1<<N)) {
    int mp = 10 * (__builtin_popcount(i) - 1);
    int s = 0;
    rep(j, N) if((1<<j) & i) s += L[j]; 
    mp += abs(s-t);
    umin(ret, mp);
  }
  return ret;
}

int dfs(int d, vector<int> &A, vector<int> &B, vector<int> &C) {
  int ret = INF;
  if(d==n) return solve(a, A) + solve(b, B) + solve(c, C);
  A.push_back(l[d]);
  umin(ret, dfs(d+1, A, B, C));
  A.pop_back();
  B.push_back(l[d]);
  umin(ret, dfs(d+1, A, B, C));
  B.pop_back();
  C.push_back(l[d]);
  umin(ret, dfs(d+1, A, B, C));
  C.pop_back();
  umin(ret, dfs(d+1, A, B, C));
  return ret;
}

//https://atcoder.jp/contests/abc119/tasks/abc119_c
int main() {
 cin >> n >> a >> b >> c; 
 rep(i,n) cin >> l[i];

 vector<int> A, B, C;
 cout << dfs(0, A, B, C) << endl;;
}
