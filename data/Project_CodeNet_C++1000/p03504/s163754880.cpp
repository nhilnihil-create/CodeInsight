
#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<double, ll> P;
typedef tuple<ll, ll, ll> t3;

#define rep(a,n) for(ll a = 0;a < n;a++)

static const ll INF = 1e15;
static const ll mod = 1e9+7;

template<typename T>
static inline void chmin(T& ref, const T  value) {
    if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T& ref, const T value) {
    if (ref < value) ref = value;
}

int main() {
    ll n, c;
    cin >> n >> c;
    vector<P> events;
    rep(i, n) {
        int s, t, c1;
        cin >> s >> t >> c1;
        events.emplace_back(s-0.5, -c1);
        events.emplace_back(t, c1);
    }
    sort(events.begin(), events.end());
    map<int,int> q;
    int u = 0;
    rep(i, n * 2) {
        auto e = events[i];
        if (e.second < 0) {
            q[-e.second]++;
        }
        else {
            q[e.second]--;
            if (!q[e.second]) {
                q.erase(e.second);
            }
        }
        chmax(u, (int)q.size());
    }
    cout << u << endl;
    return 0;
}
