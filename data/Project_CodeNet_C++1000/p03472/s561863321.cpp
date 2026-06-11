#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define inv(n, a) for(int i = 0; i < n; i++) cin >> a[i]
#define MOD 1000000007
#define INF 1e7
#define LINF 1e15
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
// 'a' = 97 'z' = 122 => 'a' = 0 'z' = 25

int main() {
    int n, h; cin >> n >> h;
    vector<pair<int, int>> P(n);
    pair<int, int> ma = make_pair(0, 0);
    rep(i, n){
        int a, b; cin >> a >> b;
        P[i] = make_pair(a, b);
        if(ma.first < a) ma = make_pair(a, b);
    }
    sort(P.begin(), P.end(), [](const auto& a, const auto& b){return a.second > b.second;});

    int dm = 0;
    bool f = false;
    int ans = 0;
    rep(i, n){
        if(P[i].second < ma.first){
            break;
            // 斬りつけに使う刀の斬りつけダメージより投擲ダメージが小さい刀は使用しない
        }
        h -= P[i].second;
        ans++;
        if(h <= 0){
            cout << ans << endl;
            return 0;
        }
    }
    ans += ceil((double)h / (double)ma.first);
    cout << ans << endl;
}