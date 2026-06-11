#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 1e9 + 7;
const int INF = 9e18;

signed main() {
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> coordinate(N);
    for (int i = 0; i < N; i++) cin >> coordinate[i].first >> coordinate[i].second;
    vector<int> x, y;
    for (auto temp : coordinate) {
        x.push_back(temp.first);
        y.push_back(temp.second);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int ans = INF;
    for (int x1 = 0; x1 < N; x1++) {
        for (int x2 = x1 + 1; x2 < N; x2++) {
            for (int y1 = 0; y1 < N; y1++) {
                for (int y2 = y1 + 1; y2 < N; y2++) {
                    int minX = x[x1], maxX = x[x2];
                    int minY = y[y1], maxY = y[y2];
                    int check = 0;
                    for (int i = 0; i < N; i++) {
                        auto temp = coordinate[i];
                        if (minX <= temp.first && temp.first <= maxX && minY <= temp.second && temp.second <= maxY) ++check;
                    }
                    if (check >= K) ans = min(ans, (maxX - minX) * (maxY - minY));
                }
            }
        }
    }
    cout << ans << endl;
}