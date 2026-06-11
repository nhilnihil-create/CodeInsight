#include <bits/stdc++.h>

using namespace std;
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;}


struct UnionFindWeighted { 
    vector<int> p, w;
    UnionFindWeighted(int n): p(n, -1), w(n) {

    }
    bool connect(int i, int j, int weight) {
        int ri = root(i);
        int rj = root(j);
        if (ri == rj) {
            return weight == w[i] - w[j];
        }
        p[ri] = rj;
        w[ri] = weight - w[i] + w[j];
        return true;
    }

    int get(int i, int j) {
        int ri = root(i);
        int rj = root(j);
        if (ri != rj) return -1;
        return w[i] - w[j];
    }

    int root(int x) {
        if (p[x] == -1) {
            return x;
        } else {
            int r = root(p[x]);
            w[x] += w[p[x]];
            return p[x] = r;
        }
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    UnionFindWeighted ufw(N);
    for (int i = 0; i < M; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        l--, r--;
        if (!ufw.connect(l, r, d)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}