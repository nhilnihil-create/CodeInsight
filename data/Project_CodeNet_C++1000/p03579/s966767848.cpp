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
const int INF = 2e18;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N + 1);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    set<int> even, odd;
    bool two = true;
    {
        vector<bool> check(N + 1, false);
        function<void(int, int)> dfs = [&](int now, int count) {
            if (count % 2 == 0) {
                if (odd.find(now) != odd.end()) two = false;
                else even.insert(now);
            } else {
                if (even.find(now) != even.end()) two = false;
                else odd.insert(now);
            }
            if (check[now]) return;
            check[now] = true;
            for (auto next : G[now]) {
                dfs(next, count + 1);
            }
        };
        dfs(1, 0);
    }
    if (two) {
        cout << even.size() * odd.size() - M << endl;
    } else {
        int base = N * (N - 1) / 2;
        cout << base - M << endl;
    }
}
