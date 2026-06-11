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

const int MOD = 1000000007;

bool comp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main(){
    int N, M; cin >> N >> M;
    vector<pair<int, int>> ab;
    rep(i,M){
        int a, b;
        cin >> a >> b;
        ab.emplace_back(a,b);
    }

    sort(ab.begin(), ab.end(), comp);

    int ans = 0;
    int right_end = 0;
    rep(i,M){
        if (right_end <= ab[i].first){
            right_end = ab[i].second;
            ans++;
        }
    }
    cout << ans << endl;

}

