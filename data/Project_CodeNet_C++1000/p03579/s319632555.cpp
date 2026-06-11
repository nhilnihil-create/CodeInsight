#include "bits/stdc++.h"
using namespace std;
using ll     = long long;
using pii    = pair<int, int>;
using pll    = pair<ll, ll>;
using vi     = vector<int>;
using vl     = vector<ll>;
using vvi    = vector<vi>;
using vvl    = vector<vl>;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}
template <class C>
void print(const C &c, std::ostream &os = std::cout) {
    std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, " "));
    os << std::endl;
}

int main() {
    ll n, m;
    cin >> n >> m;
    vvi edges(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vi col(n, 0);
    col[0]    = 1;
    bool nibu = true;
    queue<int> q, emp;
    q.push(0);
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        for (auto &ne : edges[c]) {
            if (col[ne] == 0) {
                col[ne] = -col[c];
                q.push(ne);
            } else if (col[ne] == col[c]) {
                nibu = false;
                swap(q, emp);
                break;
            }
        }
    }
    if (nibu) {
        ll x = 0, y = 0;
        for (int i = 0; i < n; ++i) {
            if (col[i] == 1)
                x++;
            else
                y++;
        }
        cout << x * y - m << "\n";
    } else {
        cout << n * (n - 1) / 2 - m << "\n";
    }
    return 0;
}