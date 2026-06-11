#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<62;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;
const int MOD = 1000000007;

int main(){
    int N,M; cin >> N >> M;
    priority_queue<pair<int, int>> pq;
    rep(i,N){
        int a; cin >> a;
        pq.push(make_pair(a, 1));
    }
    rep(i,M){
        ll b, c; cin >> b >> c;
        pq.push(make_pair(c,b));    
    }

    ll ans = 0;
    rep(i,N){
        auto p = pq.top(); pq.pop();
        ans += p.first;
        if (p.second > 1){
            pq.push(make_pair(p.first, p.second-1));
        }
    }
    
    cout << ans << endl;
}

