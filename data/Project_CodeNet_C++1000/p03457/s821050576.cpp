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

struct plan{
    int t, x, y;
};

int main(){
    int N; cin >> N;
    vector<plan> txy;
    txy.push_back(plan({0,0,0}));
    rep(i,N){
        int t, x, y; 
        cin >> t >> x >> y;
        txy.push_back(plan({t,x,y}));
    }
    for (int i = 0; i < N; i++){
        int time = txy[i+1].t - txy[i].t;
        int dist = abs(txy[i+1].x - txy[i].x) + abs(txy[i+1].y-txy[i].y);
        int diff = time-dist;
        if (diff < 0 || diff % 2 == 1){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;


}
