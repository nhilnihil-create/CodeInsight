#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define INF 1007654321
#define PI 3.14159265358979
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repp(i, s, e) for(int i = (s); i <= (e); ++i)
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define FAST_IO() ios::sync_with_stdio(0); cin.tie(0)
template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { for (auto x : v) os << x << " "; return os << "\n"; }

struct Edge {
    int u, v, w;
};

int main() {
    int L; cin >> L;
    vector<Edge> edges;
    int N;
    for(N = 1; (1<<N) <= L; ++N) {}
    for(int i = 0; i < N - 1; ++i) {
        edges.push_back({i + 1, i + 2, (1 << i)});
        edges.push_back({i + 1, i + 2, 0});
    }
    int bit = 0;
    while(L > 0) {
        for(;((1 << bit) & L) == 0; ++bit) {}
        L -= (1 << bit);
        if(L > 0) edges.push_back({bit + 1, N, L});
    }
    cout << N << " " << sz(edges) << "\n";
    for(auto &e : edges) {
        cout << e.u << " " << e.v << " " << e.w << "\n";
    }
}