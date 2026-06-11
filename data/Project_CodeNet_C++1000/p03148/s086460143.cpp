#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

const ll INF = 1LL << 40;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    vector<ll> T(N), D(N);
    rep(i, 0, N) {
        cin >> T[i] >> D[i];
    }
    vector<vector<ll>> values(N);
    rep(i, 0, N) {
        values[T[i] - 1].push_back(D[i]);
    }
    rep(i, 0, N) {
        values[i].push_back(-INF);  // 番兵
        sort(all(values[i]));
        reverse(all(values[i]));
    }
    sort(all(values));
    reverse(all(values));
    ll ans = (ll)K * (ll)K;
    priority_queue<ll, vector<ll>, greater<ll>> que1;
    priority_queue<ll> que2;
    rep(i, 0, K) {
        ans += values[i].front();
        que1.push(values[i].front());
        rep(j, 1, values[i].size()) {
            que2.push(values[i][j]);
        }
    }
    rep(i, K, N) for (auto& v : values[i]) {
        que2.push(v);
    }
    ll sum = ans;
    rrep(x, K, 1) {
        ll now = que1.top();
        que1.pop();
        ll next = que2.top();
        que2.pop();
        que1.push(next);
        sum += next - now + (ll)x * (ll)x - (ll)(x + 1) * (ll)(x + 1);
        chmax(ans, sum);
    }
    cout << ans << endl;
    return 0;
}