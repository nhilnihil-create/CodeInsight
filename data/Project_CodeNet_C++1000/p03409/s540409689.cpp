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

int ans = 100000000;

int main(){
    int N; cin >> N;
    vector<pair<int, int>> ab, cd;
    rep(i,N){
        int a, b; cin >> a >> b;
        ab.emplace_back(a,b);
    }
    rep(i,N){
        int c, d; cin >> c >> d;
        cd.emplace_back(c,d);
    }

    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    vector<bool> ab_used(N, false);
    int ans = 0;
    rep(i,N){
        int used_index = -1;
        int prev_y2 = -1;
        int x = cd[i].first;
        int y = cd[i].second;
        rep(j,N){
            if (ab_used[j]) continue;
            int x2 = ab[j].first;
            int y2 = ab[j].second;
            
            if (x > x2 && y > y2){
                if (prev_y2 < y2){
                    prev_y2 = y2;
                    used_index = j;
                }
            }
        }
        if (used_index != -1) {
            ab_used[used_index] = true;
            ans++;
        }
    }
    cout << ans << endl;

}
