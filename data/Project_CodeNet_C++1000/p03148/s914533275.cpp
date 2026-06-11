#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
#define debug(x) cerr << #x << ": " << x << '\n'
using namespace std;
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

using ll = long long;
using ull = unsigned long long;
const int INF = 1e9;
// const int MOD = 1e9 + 7;

using P = pair<ll, ll>;
int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> t(N), d(N);
    priority_queue<P> que;
    set<int> s;
    for (int i = 0; i < N; i++) {
        cin >> t.at(i) >> d.at(i);
        t[i]--;
        que.push(P(d[i], t[i]));
    }

    ll sum = 0;
    priority_queue<P, vector<P>, greater<P>> used;
    for (int i = 0; i < K; i++) {
        P p = que.top();
        que.pop();
        sum += p.first;
        if (s.count(p.second) == 1) { used.push(p); }
        s.insert(p.second);
    }
    ll ans = sum + ((ll)s.size() * (ll)s.size());

    while (!que.empty() && !used.empty()) {
        P p = que.top();
        que.pop();
        if (s.count(p.second)) {
            continue;
        } else {
            P q = used.top();
            used.pop();
            sum = sum - q.first + p.first;
            s.insert(p.second);
            chmax(ans, sum + ((ll)s.size() * (ll)s.size()));
        }
    }
    cout << ans << endl;
}
