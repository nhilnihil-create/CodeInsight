#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()



template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;


int main() {
    int n;
    cin >> n;
    vector<P> ans;
    if (n % 2 == 0) {
        int s = n * (n + 1) / 2 - (n + 1);
        rep (i, 1, n + 1) {
            rep (j, i + 1, n + 1) {
                if (i + j == n + 1) continue;
                ans.emplace_back(make_pair(i, j));
            }
        }
    } else {
        int s = (n - 1) * n / 2;
        rep (i, 1, n) {
            ans.emplace_back(make_pair(i, n));
        }
        rep (i, 1, n) {
            rep (j, i + 1, n) {
                if (i + j == n) continue;
                ans.emplace_back(make_pair(i, j));
            }
        }
    }
    cout << ans.size() << endl;
    rep (i, ans.size()) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}

