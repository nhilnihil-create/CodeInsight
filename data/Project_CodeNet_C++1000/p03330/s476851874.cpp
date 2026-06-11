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


int main() {
  int n, c; cin >> n >> c;
  vector<vector<int>> d(c, vector<int>(c));
  rep(i,c) rep(j,c) cin >> d[i][j];

  vector<int> group[3];
  rep(i,n) rep(j,n) {
    int q; cin >> q;
    group[(i+j+2) % 3].push_back(q-1);
  }

  vector<vector<int>> cost(3, vector<int>(c));
  rep(g, 3)
    rep(to, c)
      for(auto from : group[g])
        cost[g][to] += d[from][to];

  int ans = 1 << 30;
  rep(c0, c) rep(c1, c) rep(c2, c) if(c0 != c1 && c1 != c2 && c0 != c2) 
    umin(ans, cost[0][c0] + cost[1][c1] + cost[2][c2]); 
  cout << ans << endl;
}
