#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define PI 3.14159265358979
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repp(i, s, e) for(int i = (s); i <= (e); ++i)
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define FAST_IO() ios::sync_with_stdio(0); cin.tie(0)
template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { for (auto x : v) os << x << " "; return os << "\n"; }
template<class U, class V>
ostream& operator<<(ostream &os, const pair<U, V> &p) { return os << "(" << p.first << "," << p.second << ")";}

int main() {
    int N, K; cin >> N;
    K = N / 2;
    vector<pii> edges;
    if(N % 2 == 0) {
        // N = 2K
        repp(i, 1, K) {
            repp(j, i + 1, K) {
                edges.push_back({i, j});
                edges.push_back({i, 2 * K + 1 - j});
                edges.push_back({2 * K + 1 - i, j});
                edges.push_back({2 * K + 1 - i, 2 * K + 1 - j});
            }
        }
    } else {
        // N = 2K + 1
        repp(i, 1, K) {
            repp(j, i + 1, K) {
                edges.push_back({i, j});
                edges.push_back({i, 2 * K + 1 - j});
                edges.push_back({2 * K + 1 - i, j});
                edges.push_back({2 * K + 1 - i, 2 * K + 1 - j});
            }
        }
        repp(i, 1, N - 1) {
            edges.push_back({i, N});
        }
    }
    cout << sz(edges) << "\n";
    for(auto &e : edges) cout << e.first << " " << e.second << "\n";
}